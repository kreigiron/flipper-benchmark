#include "memory-benchmark.h"
#include "string.h"
#include <iostream>
using namespace std;

memoryBenchmark::memoryBenchmark(){
  cout << "Memory Benchmark";
};

int memoryBenchmark::doBenchmark(){
  return 0;
};

string * memoryBenchmark::log(){
  return new string("");
};
