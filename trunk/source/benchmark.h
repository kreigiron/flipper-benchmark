#include <string>
/**
Clase base para la evaluacion comparativa
*/
using namespace std;

class benchmark {
public:
  virtual int doBenchmark() = 0;
  virtual string* log() = 0;  
};
