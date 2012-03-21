#include "benchmark.h"
#include <string>

using namespace std;

class flopBenchmark: public benchmark{
 public:
  flopBenchmark();
  ~flopBenchmark(){};
  int doBenchmark();
  string *log();
 protected:
  int dummy;
};
