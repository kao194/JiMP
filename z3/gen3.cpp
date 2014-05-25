#include "gen3.h"


gen3::gen3(int _min, int _max, int _seed){
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
   counter = 0;
}

bool gen3::setSeed(int _seed){
   if (_seed < 0)
      return false;
   seed = _seed;
   counter = 0;
   return true;
}

int gen3::randomize(){
   int x = counter++;
   return  abs((int)(seed*sin(x+seed)))%(max-min+1) + min;
}
