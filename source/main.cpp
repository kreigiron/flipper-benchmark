#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ogcsys.h>
#include <gccore.h>

#include <ogc/ipc.h>
     
    static void *xfb = NULL;
    static GXRModeObj *rmode = NULL;
     
    typedef void (*Loader_Entry)(void);
    Loader_Entry loader = (Loader_Entry)0x80001800;
     
    void Reboot()
    {
            int fd = IOS_Open("/dev/stm/immediate", 0);
            IOS_Ioctl(fd, 0x2001, NULL, 0, NULL, 0);
            IOS_Close(fd);
    }
     
    int main(int argc, char **argv) {
     
            VIDEO_Init();
            PAD_Init();
           
            switch(VIDEO_GetCurrentTvMode()) {
                    case VI_NTSC:
                            rmode = &TVNtsc480IntDf;
                            break;
                    case VI_PAL:
                            rmode = &TVPal528IntDf;
                            break;
                    case VI_MPAL:
                            rmode = &TVMpal480IntDf;
                            break;
                    default:
                            rmode = &TVNtsc480IntDf;
                            break;
            }
     
            xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));
            console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);
           
            VIDEO_Configure(rmode);
            VIDEO_SetNextFramebuffer(xfb);
            VIDEO_SetBlack(FALSE);
            VIDEO_Flush();
            VIDEO_WaitVSync();
            if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();
     
            printf("\n");
            printf("Hello World!\n");
            printf("Return to Loader by Pressing A\n");
            printf("Reboot by Pressing START\n");
     
            while(1) {
                    VIDEO_WaitVSync();
                    PAD_ScanPads();
     
                    int buttonsDown = PAD_ButtonsDown(0);
                    if( buttonsDown & PAD_BUTTON_A ) {
                            printf("Button A pressed.\n");
                            loader();
                    }
                    if ( buttonsDown & PAD_BUTTON_START ) {
                            printf("Start Button Pressed \n");
                            Reboot();
                    }
            }
     
            return 0;
    }
