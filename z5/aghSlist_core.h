#ifndef AGH_SLIST_CORE_H
#define AGH_SLIST_CORE_H

template<class T>
aghSlist<T>::aghSlist(aghSlist<T> const & _right) {
   this->aghContainer<T>::operator =(_right);
}

template<class T>
aghSlist<T>::aghSlist(aghContainer<T> const & _right) {
   this->aghContainer<T>::operator =(_right);
}

template<class T>
void aghSlist<T>::deallocate()
{
   while(_start!=NULL)
      remove(0);
}

template<class T>
bool aghSlist<T>::insert(int _index, T const& _obj)
{  
   if((_index<0)||(_index>_size))
      return false;
   aghSnode<T>* tmp = new aghSnode<T>();
   tmp->value=_obj;
   aghSnode<T>* ip=0;
   int count=0;

   for(aghSnode<T>* i=_start; i!=0 && count<_index;i=i->_next,count++){
      ip=i;
   }
   if(ip)
   {
      tmp->_next=ip->_next;
      ip->_next=tmp;
   }
   else
   {
      tmp->next=_start;
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
bool aghSlist<T>::remove(int _index)
{
   if((_index<0)||(_index>=_size))
      return false;
   aghSnode<T>* ip=0;
   aghSnode<T>* i=_start;
   int count=0;
   for(; i!=0 && count<_index;i=i->_next,count++){
      ip=i;
   }
   if(ip)
   {
      ip->_next=ip->_next->_next;
      if(ip->_next==NULL)
         _end=ip;
   }
   else
   {
      _start=_start->_next;
      if(_start!=NULL)
      {
         if(_start->_next==NULL)
            _end=_start;
      }
      else
         _end=NULL;
   }
   delete i;
   size--;
   return true;
}

template<class T>
T& aghSlist<T>::at(int _index)const
{   
   if(_index<0||_index>=_size)
      throw aghException(1,"Bad index"); 
   aghDnode<T>* tmp=_start;
   for(int i=0;i<_index;i++)
      tmp=tmp->_next;
   return tmp->value;
}


#endif
