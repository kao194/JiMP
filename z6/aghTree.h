#ifndef AGH_TREE_H
#define AGH_TREE_H

#include "aghContainer.h"

/**
* \class aghTree
* \date 15.06.2014
* \brief Container which takes care for data in it in BST tree
*/
template<class T>
class aghTree: public aghContainer<T> {
private:
   aghTnode<T>* _root;
   int _size;
   void deallocate(aghTnode<T> * _node);
   
public:
   
   /// \brief default constructor
   aghTree(){
      _root=NULL;
      _size=0;
   };

   /// \brief copying constructor
   ///
   /// \param _right - object to make copy of   
   aghTree(aghTree<T> const & _right);

   /// \brief constructor which takes parent object and makes Vector from it
   ///
   /// \param _right - object to make copy of   
   aghTree(aghContainer<T> const & _right);

   /// \brief virtual destructor
   virtual ~aghTree(){
      deallocate(_root);
   };

   void fixIndex(int & param, aghTnode<T> * _node);

   /// \brief adds an element to a container, on certain place
   ///
   /// \param int - number of the place to insert element in
   /// \param _obj - element to put to container
   /// \return TRUE if number given in first param shows correct place, FALSE otherwise
   bool insert(int, T const&);

   /// \brief returns an element from a position
   ///
   /// \param int - position of element
   /// \return & of the element
   T& at(int) const;

   /// \brief returns amount of elements in container (not the amount of reserved memory!)
   ///
   /// \return int - amount of elements 
   int size(void) const{int _s=_size; return _s;};

   /// \brief removes element on a given position
   ///
   /// \param int - position of element
   /// \return TRUE if succeeded, FALSE otherwise
   bool remove(int i);

   /// \brief operator =, as it is
   /// 
   /// \param _right - container function is assigning from
   /// \return *this
   //using aghContainer<T>::operator=;
   aghTree<T> const & operator=(aghTree<T> const & other);
};

#endif
