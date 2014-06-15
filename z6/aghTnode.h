#ifndef AGH_TNODE_H
#define AGH_TNODE_H

/**
* \class aghTnode
* \date 15.06.2014
* \brief Element of BST tree
*/
template<class T>
class aghTnode{

public:   
   aghTnode<T>* _left; /// \left element
   aghTnode<T>* _right; /// \right element
   T _value; /// \value of element
   int _index; /// \index made in search
   /// \brief default constructor
   aghTnode(){
      _left=NULL;
      _right=NULL;
      _index=-1;
   };
};

#endif
