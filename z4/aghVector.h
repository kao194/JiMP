#ifndef AGH_VECTOR_H
#define AGH_VECTOR_H

#include "aghContainer.h"

template<class T>
class aghVector: public aghContainer<T> {
public:
   bool insert(int, T const&);
   T& at(int) const;
   int size(void) const{return 1;};
   bool remove(int i){return 1;};
};

#endif
