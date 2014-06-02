#ifndef AGH_VECTOR_H
#define AGH_VECTOR_H

#include "aghContainer.h"

/**
* \class aghVector
* \author Krzysztof Waclawik, Jakub Slowik
* \date 1.06.2014
* \brief Container which takes care for data in it in array (vector)
*/
template<class T>
class aghVector: public aghContainer<T> {
private:
   int _pool; ///<additional slots to reserve
   int _size; ///<amount of actually taken slots
   int _reserved; ///<amount of already reserved memory
   T* _array; ///<place to keep elements

   /// \brief reserved new space based on _pool and param given
   ///
   /// \param int -  if it's 1 - reserves _reserved+_pool space, _reserved-_pool space otherwise
   void reserve(int);//int == 1 --expands; shrinks elsewhere

   /// \brief deallocates all memory
   ///
   void deallocate();
public:
   
   /// \brief default constructor
   aghVector(){
      _pool = 5;
      _reserved=0;
      _size=0;
      _array=NULL;
   };

   /// \brief copying constructor
   ///
   /// \param _right - object to make copy of   
   aghVector(aghVector<T> const & _right);

   /// \brief constructor which takes parent object and makes Vector from it
   ///
   /// \param _right - object to make copy of   
   aghVector(aghContainer<T> const & _right);

   /// \brief virtual destructor
   virtual ~aghVector(){
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
   aghVector<T> const & operator=(aghVector<T> const &);
};

#endif
