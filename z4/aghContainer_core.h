#ifndef AGH_CONTAINER_CORE_H
#define AGH_CONTAINER_CORE_H

template<class T>
void aghContainer<T>::append(T const& _obj)
{
   if(!insert(size(),_obj))
      1;
}

template<class T>
bool aghContainer<T>::replace(int _place, T const& _obj)
{
   if((_place<0)||(_place>size()))
      return false;
   if(remove(_place))
      insert(_place,_obj);
   else
      return false;
   return true;
}

template<class T>
void aghContainer<T>::clear()
{
   for(int i=0;i<size();i++)
      remove(0);
}

template<class T>
int aghContainer<T>::indexOf(T const& _value, int _from) const
{
   for(int i=_from;i<size();i++)
   {
      if(at(i)==_value)
         return i;
   }
   return -1;
}

template<class T>
bool aghContainer<T>::contains(T const& _value, int _from)const
{
//wondering about just checking indexOf()!=-1, but I guess for such short code it would just complicate
   for(int i=_from;i<size();i++)
   {
      if(at(i)==_value) 
         return true;
   }
   return false;
}

template<class T>
aghContainer<T> const & aghContainer<T>::operator=(aghContainer<T> const & right) {
   if(this != &right){
      if(!this->isEmpty())
         this->clear();
      *this += right;//it's (*this) += right, overloaded operator
   }
   return *this;
}

template<class T>
bool aghContainer<T>::operator==(aghContainer<T> const& right)
{
   if(this->size()!=right.size())
      return false;
   for(int i=0;i<size();i++)
   {
      if(at(i)!=right.at(i))
      {
         return false;
      }
   }
   return true;
}

template<class T>
bool aghContainer<T>::operator!=(aghContainer<T> const& right)
{
   return !(*this==right);
}

template<class T>
aghContainer<T>& aghContainer<T>::operator+=(aghContainer<T> const& right)
{
   int _size=right.size(); //just in case a+=a;
   for(int i=0;i<_size;i++)
   {
      append(right.at(i));
   }
   return *this;
}

template<class T>
aghContainer<T>& aghContainer<T>::operator<<(aghContainer<T> const& right)
{
   return *this+=right;
}


#endif
