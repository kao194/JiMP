#ifndef GEN_2_H
#define GEN_2_H
#include "generator.h"

//random number generator based on ax^2+bx+c

class gen2:public generator{
private:
   int x_2, x_1, x_0; //those saves numbers to faster calculations, a,b,c from the equation above;
   int counter; //to save amount of already called numbers;
public:
   gen2(int min, int max, int seed);
   bool setSeed(int _seed);//calling srand() function in addition to base function
   int randomize();
};

#endif
