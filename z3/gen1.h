#ifndef GEN_1_H
#define GEN_1_H
#include "generator.h"

class gen1:public generator{
public:
   gen1(int min, int max, int seed);
   bool setSeed(int _seed);//calling srand() function in addition to base function
   int randomize();
};

#endif
