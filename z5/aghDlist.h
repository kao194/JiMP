#ifndef AGH_DLIST_H
#define AGH_DLIST_H

#include "aghContainer.h"

/**
* \class aghDlist
* \author Krzysztof Waclawik, Jakub Slowik
* \date 1.06.2014
* \brief Container which takes care for data in it in 1-directional list
*/
template<class T>
class aghDlist: public aghContainer<T> {
private:
   aghDnode<T>* _start;
   aghDnode<T>* _end;
   int _size;
   void deallocate();
public:
   
   /// \brief default constructor
   aghDlist(){
      _start=NULL;
      _end=NULL;
      _size=0;
   };

   /// \brief copying constructor
   ///
   /// \param _right - object to make copy of   
   aghDlist(aghDlist<T> const & _right);

   /// \brief constructor which takes parent object and makes Vector from it
   ///
   /// \param _right - object to make copy of   
   aghDlist(aghContainer<T> const & _right);

   /// \brief virtual destructor
   virtual ~aghDlist(){

   };

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
   using aghContainer<T>::operator=;
};

#endif
