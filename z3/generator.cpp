#include "generator.h"
#include <iostream>
#include <cstdarg>
using namespace std;

/*
generator::generator(int _min, int _max, int _seed){
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
}
*/

bool generator::setMin(int _min){
   if (_min > max)
      return false;
   min = _min;
   return true;
}

bool generator::setMax(int _max){
   if (_max < min)
      return false;
   max = _max;
   return true;
}

bool generator::setSeed(int _seed){
   if (_seed < 0)
      return false;
   seed = _seed;
   return true;
}

int generator::getMin(){
   return min;
}

int generator::getMax(){
   return max;
}

int generator::getSeed(){
   return seed;
}
