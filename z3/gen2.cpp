#include "gen2.h"
#include <iostream>
#include <cstdlib>
using namespace std;



gen2::gen2(int _min, int _max, int _seed){
   //we assume _min and _max are correct, if not just swap them (want to avoid throwing exceptions in constructor)
   if (_min <= _max)
   {
      min = _min;
      max = _max;
   }
   else
   {
      min = _max;
      max = _min;
   }
   seed = _seed;
   x_2 = (seed % 29)/((seed%6) +1);
   x_1 = -(seed % 13);
   x_0 = seed % 43;
   counter = 0;
}

bool gen2::setSeed(int _seed){
   if (_seed < 0)
      return false;
   seed = _seed;  //I use one seed to get all three params
   x_2 = (seed % 29)/((seed%6) +1);
   x_1 =-(seed % 13);
   x_0 = seed % 43;
   counter = 0;
   return true;
}

int gen2::randomize(){
   int x = counter++;
   return  abs(x_2*(x^2)+x_1*x+x_0)%(max-min+1) + min;
}

