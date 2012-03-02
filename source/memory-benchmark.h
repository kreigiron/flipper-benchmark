#include "benchmark.h"
#include <string>

using namespace std;

class memoryBenchmark: public benchmark{
 public:
  memoryBenchmark();
  int doBenchmark();
  string *log();
};
