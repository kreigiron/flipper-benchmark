#include "memory-benchmark.h"
#include "string.h"
#include <iostream>
using namespace std;

memoryBenchmark::memoryBenchmark(){
  cout << "Memory Benchmark";
};

int memoryBenchmark::doBenchmark(){
  // write 1024 1byte, byte by byte, of random data chuncks from cpu to main memory}
  
  writeToLog("Start 1024x1byte test");
  for(int i = 0; i < 1024; i++){
    char c;
    testKb[i] = c;
  }
  writeToLog("End 1024x1 byte test");
 
  // read 1024 1kb chunks from main memory to cpu

  writeToLog("Start 1024x1kb test");
  for(int i = 0; i < 1024; i++){
    char c;
    testKb[i] = c;
  }
  writeToLog("End 1024x1kb test");

  // write 1024 1kb chuncks from cpu to main memory
  
  // read 1024 1kb chunks from main memory to cpu

 return 0;
};

string * memoryBenchmark::log(){
  return new string("");
};
