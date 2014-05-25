#ifndef GEN_3_H
#define GEN_3_H
#include "generator.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


//random number generator based on ax^2+bx+c

class gen3:public generator{
private:
   int counter; //to save amount of already called numbers;
public:
   gen3(int min, int max, int seed);
   bool setSeed(int _seed);//calling srand() function in addition to base function
   int randomize();
};

#endif
