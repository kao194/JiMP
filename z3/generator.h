#ifndef GENERATOR_H
#define GENERATOR_H

class generator{
protected:
   int min;//minimal random value
   int max;//maximal random value
   int seed;//number which will alter return values
public:
   //generator(int min, int max, int seed) = 0; not needed, as you can't create object of that class and its not inherited
   //functions below return true if succeeded, false when wrong number was given (like min>max or so)
   virtual bool setMin(int min);
   virtual bool setMax(int max);
   virtual bool setSeed(int seed);
   //
   virtual int getMin();
   virtual int getMax();
   virtual int getSeed();
   //
   virtual int randomize() = 0;
};

#endif