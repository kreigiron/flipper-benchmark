#include "benchmark.h"
#include <ctime>
#include <cstdio>

using namespace std;

int benchmark::writeToLog(string log){
  int start = clock();
  char clockbuffer[50];
  int n = sprintf(clockbuffer, "%d", start);
  benchmark_log += clockbuffer;
  benchmark_log += ": ";
  benchmark_log += log;
  benchmark_log += "\n";

  return 0;
}
