#ifndef AGH_VECTOR_H
#define AGH_VECTOR_H

#include "aghContainer.h"

template<class T>
class aghVector: public aghContainer<T> {
private:
   int _pool; //additional slots to reserve
   int _size; //amount of actually taken slots
   int _reserved; //amount of already reserved memory
   T* _array; //place to keep elements
   void reserve(int);//int == 1 --expands; shrinks elsewhere
   void deallocate();
public:
   aghVector(){
      _pool = 5;
      _reserved=0;
      _size=0;
      _array=NULL;
   };
   aghVector(aghVector<T> const & _right);
   aghVector(aghContainer<T> const & _right);
   virtual ~aghVector(){
      deallocate();
   };
   bool insert(int, T const&);
   T& at(int) const;
   int size(void) const{return _size;};
   bool remove(int i);
   aghVector<T> const & operator=(aghVector<T> const &);
};

#endif
