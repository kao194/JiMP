#ifndef AGH_VECTOR_CORE_H
#define AGH_VECTOR_CORE_H

template<class T>
aghVector<T>::aghVector(aghVector<T> const & _right) {
   _array = NULL;
   _size = 0;
   _reserved = 0;
   _pool=_right._pool;

   this->aghContainer<T>::operator =(_right);
}

template<class T>
aghVector<T>::aghVector(aghContainer<T> const & _right) {
   _array = NULL;
   _size = 0;
   _reserved = 0;
   _pool=5;
   this->aghContainer<T>::operator =(_right);
}

template<class T>
void aghVector<T>::reserve(int a)
{
   if(a==1)
      _reserved+=_pool;
   else
      _reserved-=_pool;
   T* tmp=NULL;   
   if(_array!=NULL)
   {
      tmp=_array;
   }
   _array=new T[_reserved];
   if(tmp!=NULL)
   {
      for(int i=0;i<_size;i++)
      {
         _array[i]=tmp[i];
         tmp[i].~T();
      }
      delete[] tmp;
   }
}

template<class T>
void aghVector<T>::deallocate()
{
   if(_array!=NULL)
   {
      for(int i=0;i<_size;i++)
         _array[i].~T();
      delete [] _array;
      _array=NULL;
   }
}

template<class T>
bool aghVector<T>::insert(int _index, T const& _obj)
{
   if((_index<0) || (_index>_size))
      return false;
   if((_reserved-_size)==0)
      reserve(1);
   for(int i=_size;i>_index;i--)
   {
      _array[i]=_array[i-1];
   }
   _array[_index]=_obj;
   _size++;
   return true;
}

template<class T>
bool aghVector<T>::remove(int _index)
{
   if((_index<0) || (_index>=_size))
      return false;
   _array[_index].~T();
   for(int i=_index;i<(_size-1);i++)
      _array[i]=_array[i+1];
   _size--;
   if((_reserved-_size)>_pool)
      reserve(0);
   return true;
}

template<class T>
T& aghVector<T>::at(int _index)const
{
   if((_index<0) || (_index>=size()))
      throw aghException(1,"Bad dimensions");   
   return _array[_index];
}

/*
template<class T>
aghVector<T> const & aghVector<T>::operator=(aghVector<T> const & other)
{
   this->aghContainer<T>::operator =(other);
   return *this;
}*/

#endif
