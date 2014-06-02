#ifndef AGH_CONTAINER_H
#define AGH_CONTAINER_H

#include "aghInclude.h"

/**
* \class aghContainer
* \author Krzysztof Waclawik, Jakub Slowik
* \date 31.05.2014
* \brief Interface to take care of containers
*/
template<class T>
class aghContainer{
public:

   aghContainer(){};   

   virtual ~aghContainer(){};
   
   /// \brief function adds an element to a container
   ///
   /// \param _obj - element to add
   void append(T const& _obj);

   /// \brief adds an element to a container, on certain place
   ///
   /// \param int - number of the place to insert element in
   /// \param _obj - element to put to container
   /// \return TRUE if number given in first param shows correct place, FALSE otherwise
   virtual bool insert(int, T const&)=0;
   
   /// \brief swaps an element given as a param on certain place
   ///
   /// \param int - number of the place to insert element in
   /// \param _obj - element to put to container
   /// \return TRUE if number given in first param shows correct place, FALSE otherwise
   bool replace(int, T const&);

   /// \brief returns an element from a position
   ///
   /// \param int - position of element
   /// \return & of the element
   virtual T& at(int) const=0;

   /// \brief returns amount of elements in container (not the amount of reserved memory!)
   ///
   /// \return int - amount of elements 
   virtual int size(void) const=0;

   /// \brief removes element on a given position
   ///
   /// \param int - position of element
   /// \return TRUE if succeeded, FALSE otherwise 
   virtual bool remove(int)=0;

   /// \brief cleans container
   void clear(void);

   /// \brief checks if container is empty or not
   ///
   /// \return TRUE if container is empty, FALSE otherwise 
   bool isEmpty(void){if(size()==0) return true; return false;}

   /// \brief gives index of given element
   ///
   /// \param _value - element to search for
   /// \param _from - element to start searching from
   /// \return index of found element, -1 otherwise 
   int indexOf(T const& _value, int _from = 0) const;

   /// \brief searches for given element
   ///
   /// \param _value - element to search for
   /// \param _from - element to start searching from
   /// \return TRUE if element was found, FALSE otherwise
   bool contains(T const& _value, int _from = 0) const;

   /// \brief operator =, as it is
   /// 
   /// \param _right - container function is assigning from
   /// \return *this
   aghContainer<T> const & operator=(aghContainer<T> const &);

   /// \brief checks if both containers have the same elements
   ///
   /// \param _right - second container to compare data
   /// \return TRUE if both containers have same elements, FALSE otherwise
   bool operator==(aghContainer<T> const& right);

   /// \brief checks if containers differ
   ///
   /// \param _right - second container to compare data
   /// \return TRUE if containers differ, FALSE otherwise
   bool operator!=(aghContainer<T> const& right);

   /// \brief returns an element from a position
   ///
   /// \param int - position of element
   /// \return & of the element
   T& operator[](int n) const{return at(n);}

   /// \brief appends container with all elements from right container
   ///
   /// \param container with elements
   /// \return &this
   aghContainer<T>& operator+=(aghContainer<T> const& right);

   /// \brief appends container with given element
   ///
   /// \param element to append
   /// \return &this
   aghContainer<T>& operator+=(T const& element){append(element);return *this;}

   /// \brief appends container with given element
   ///
   /// \param element to append
   /// \return &this
   aghContainer<T>& operator<<(T const& element){append(element);return *this;}

   /// \brief appends container with all elements from right container
   ///
   /// \param container with elements
   /// \return &this
   aghContainer<T>& operator<<(aghContainer<T> const& right);
};

template<class T>
ostream& operator<<(ostream& _out, aghContainer<T> const& right)
{
   for(int i=0; i<right.size(); i++) {
      _out << right.at(i) << endl;
   }
   return &_out;
}

#endif
