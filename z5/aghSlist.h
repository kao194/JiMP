#ifndef AGH_SLIST_H
#define AGH_SLIST_H

#include "aghContainer.h"
#include "aghSnode.h"

/**
* \class aghSlist
* \date 1.06.2014
* \brief Container which takes care for data in it in 1-directional list
*/
template<class T>
class aghSlist: public aghContainer<T> {
private:
   aghSnode<T>* _start;
   aghSnode<T>* _end;
   int _size;
   void deallocate();
public:
   
   /// \brief default constructor
   aghSlist(){
      _start = NULL;
      _end=NULL;
      _size=0;
   };

   /// \brief copying constructor
   ///
   /// \param _right - object to make copy of   
   aghSlist(aghSlist<T> const & _right);

   /// \brief constructor which takes parent object and makes Vector from it
   ///
   /// \param _right - object to make copy of   
   aghSlist(aghContainer<T> const & _right);

   /// \brief virtual destructor
   virtual ~aghSlist(){
      deallocate();
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
   int size(void) const{return _size;};

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
