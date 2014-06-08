#ifndef AGH_DLIST_CORE_H
#define AGH_DLIST_CORE_H

template<class T>
aghDlist<T>::aghDlist(aghDlist<T> const & _right) {
   this->aghContainer<T>::operator =(_right);
}

template<class T>
aghDlist<T>::aghDlist(aghContainer<T> const & _right) {
   this->aghContainer<T>::operator =(_right);
}

template<class T>
bool aghDlist<T>::insert(int _index, T const& _obj)
{  
   if((_index<0)||(_index>_size))
      return false;
   aghDnode<T>* tmp = new aghDnode<T>();
   tmp->_next=NULL;
   tmp->_prev=NULL;
   tmp->value=_obj;
   aghDnode<T>* ip=0;
   int count=0;
   for(aghDnode<T>* i=_start; i!=0 && count<_index;i=i->_next,count++){
      ip=i;
   }
   if(ip)
   {
      tmp->_next=ip->_next;
      tmp->_prev=ip;
      ip->_next=tmp;
      if(tmp->_next!=NULL)
         tmp->_next->_prev=tmp;
   }
   else
   {
      tmp->_next=_start;
      if(tmp->_next!=NULL)
         tmp->_next->_prev=tmp;
      tmp->_prev=NULL;
      _start=tmp;
   }
   if(_end==0)
      _end=_start;
   if(tmp->_next==0)
      _end=tmp;
   _size++;
   return true;
}

template<class T>
bool aghDlist<T>::remove(int _index)
{
   if((_index<0)||(_index>=_size))
      return false;
   aghDnode<T>* ip=0;
   aghDnode<T>* i=_start;
   int count=0;
   for(; i!=0 && count<_index;i=i->_next,count++){
      ip=i;
   }
   if(ip)
   {
      ip->_next=ip->_next->_next;
      if(ip->_next==NULL)
      {
         _end=ip;
      }
      else
         ip->_next->_prev=ip;
   }
   else
   {
      _start=_start->_next;
      if(_start!=NULL)
      {
         _start->_prev=NULL;
         if(_start->_next==NULL)
            _end=_start;
         else
            _start->_next->_prev=NULL;
      }
      else
         _end=NULL;
   }
   delete i;
   _size--;
   return true;
}

template<class T>
T& aghDlist<T>::at(int _index)const
{  
   if(_index<0||_index>=_size)
      throw aghException(1,"Bad index");
   aghDnode<T>* tmp=_start;
   for(int i=0;i<_index;i++)
      tmp=tmp->_next;
   return tmp->value;
}

/*
template<class T>
aghDlist<T> const & aghDlist<T>::operator=(aghDlist<T> const & other)
{
   this->aghContainer<T>::operator =(other);
   return *this;
}
*/

#endif
