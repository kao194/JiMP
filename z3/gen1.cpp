//#include "aghInclude.h"
#include "generator.h"
#include "gen1.h"
#include <iostream>
#include <cstdlib>
using namespace std;


gen1::gen1(int _min, int _max, int _seed){
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
   srand(seed);
}

bool gen1::setSeed(int _seed){
   if (_seed < 0)
      return false;
   seed = _seed;
   srand(seed);
   return true;
}

int gen1::randomize(){
   return rand() % (max-min+1) + min;
}

