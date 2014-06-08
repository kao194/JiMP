#ifndef AGH_DNODE_H
#define AGH_DNODE_H

/**
* \class aghSnode
* \date 5.06.2014
* \brief Element of 1-directional list
*/
template<class T>
class aghDnode{

public:
   /// \brief default constructor
   aghDnode<T>* _prev;
   aghDnode<T>* _next;
   T value;
   aghDnode(){
      _next=NULL;
      _prev=NULL;
   };
};

#endif
