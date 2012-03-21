#include "benchmark.h"
#include <string>

using namespace std;

class memoryBenchmark: public benchmark{
 public:
  memoryBenchmark();
  ~memoryBenchmark(){};
  int doBenchmark();
  string *log();
 protected:
  static char testKb[1024];
  static char testMb[1024][1024];
};
