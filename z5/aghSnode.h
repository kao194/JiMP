#ifndef AGH_SNODE_H
#define AGH_SNODE_H

/**
* \class aghSnode
* \date 5.06.2014
* \brief Element of 1-directional list
*/
template<class T>
class aghSnode{

public:
   /// \brief default constructor
   aghSnode<T>* _next;
   T value;
   aghSnode(){
      _next=NULL;
   };
};

#endif
