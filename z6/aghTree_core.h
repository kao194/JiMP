#ifndef AGH_TREE_CORE_H
#define AGH_TREE_CORE_H

template<class T>
aghTree<T>::aghTree(aghTree<T> const & _right) {
   _root=NULL;
   _size=0;
   this->aghContainer<T>::operator =(_right);
}

template<class T>
aghTree<T>::aghTree(aghContainer<T> const & _right) {
   _root=NULL;
   _size=0;
   this->aghContainer<T>::operator =(_right);
}

template<class T>
void aghTree<T>::deallocate(aghTnode<T> * _node)
{
   if(_node!=NULL)
   {
      deallocate(_node->_left);
      deallocate(_node->_right);
      delete _node;
      _node=NULL;//dunno if needed
      _size--;
   }
   //no need for fixing indexes after that, as entire tree should be empty
}

template<class T>
void aghTree<T>::fixIndex(int & param, aghTnode<T> * _node)
{
   if(_node!=NULL)
   {
      fixIndex(param,_node->_left);
      _node->_index=param;
      param++;
      fixIndex(param,_node->_right);
   }
}

template<class T>
bool aghTree<T>::insert(int a, T const& _obj)
{  
   //a is ignored, as its an index of an element, which is... well, ignored while inserting to tree
   aghTnode<T>* tmp = new aghTnode<T>();
   tmp->_left=NULL;
   tmp->_right=NULL;
   tmp->_value=_obj;
   aghTnode<T>* i=_root;
   aghTnode<T>* ip=NULL;
  
   if(_root==NULL)
   {
      //adding item at first spot //empty tree;
      _root=tmp;
   }
   else
   {
      bool _gl = false;
      while(i!=NULL)
      {
         ip=i;
         if(i->_value>=tmp->_value)
         {
            i=i->_left;
            _gl=true;
         }
         else
         {
            i=i->_right;
            _gl=false;
         }
      }//finding element, i shows place(practically useless here, wondering about reducing it)
      if(_gl)
         ip->_left=tmp;
      else
         ip->_right=tmp;
   }
   _size++;
   int _ind=0;
   fixIndex(_ind,_root);
   if((_size)!=_ind)
      cout << "cos jest zle" << endl;
   return true;
}

template<class T>
bool aghTree<T>::remove(int _index)
{
   if((_index<0)||(_index>=_size))
      return false;
   aghTnode<T>* tmp=_root;
   aghTnode<T>* prev=NULL;
   bool _gl = false;
   while(tmp->_index!=_index)
   {
      prev=tmp;
      if(tmp->_index>_index)
      {
         tmp=tmp->_left;
         _gl=true;
      }
      else
      {
         tmp=tmp->_right;
         _gl=false;
      }
   }
   //case0::removing root
   if(prev==NULL)
   {
      //case01::removing root while left subtree is empty and right has elements
      if(tmp->_left==NULL)
      {
         if(tmp->_right!=NULL)
         {
            _root=tmp->_right;
            delete tmp;
         }
         //case02::removing root while both subtrees are empty //so tree will be empty
         else
         {
            delete _root;
            _root=NULL;
         }
      }
      //case03::removing root while right subree is empty and left has elements
      else if (tmp->_right==NULL)
      {
         if(tmp->_left!=NULL)
         {
            _root=tmp->_left;
            delete tmp;
         }
      }
      //case00::removing root with both subtrees - choosed left one to search for new root
      else
      {
         aghTnode<T>* tmp2=_root->_left;
         aghTnode<T>* prev2=_root;
         while(tmp2->_right!=NULL)
         {
            prev2=tmp2;
            tmp2=tmp2->_right;
         }
         tmp->_value=tmp2->_value;
         prev2->_right=tmp2->_left;//takes NULL pointer as well
         delete tmp2;//should work
      }
   }
   else
   {
      //case1::removing leaf
      if(tmp->_left==NULL && tmp->_right==NULL)
      {
         if(_gl)
            prev->_left=NULL;
         else
            prev->_right=NULL;
         delete tmp;
      }
      else
      //case2::most boring one, removing just ordinary element
      {
         aghTnode<T>* tmp2=tmp->_left;
         aghTnode<T>* prev2=tmp;
         if(tmp2!=NULL)
         {
            while(tmp2->_right!=NULL)
            {
               prev2=tmp2;
               tmp2=tmp2->_right;
            }
            tmp->_value=tmp2->_value;
            prev2->_right=tmp2->_left;//takes NULL pointer as well
            delete tmp2;//should work
            prev2->_left=NULL;
         }
         else
         {
            prev->_right=tmp->_right;
            delete tmp;
         }

      }
   }
   _size--;
   int _ind=0;
   fixIndex(_ind,_root);
   if((_size)!=_ind)
   cout << "cos jest zle" << endl;
   return true;
}

template<class T>
T& aghTree<T>::at(int _index)const
{  
   if(_index<0||_index>=_size)
      throw aghException(1,"Bad index");
   aghTnode<T>* tmp=_root;
   while(tmp->_index!=_index)
   {
      if(tmp->_index>_index)
         tmp=tmp->_left;
      else
         tmp=tmp->_right;
   }
   return tmp->_value;
}


template<class T>
aghTree<T> const & aghTree<T>::operator=(aghTree<T> const & other)
{
   this->aghContainer<T>::operator =(other);
   int _ind=0;
   fixIndex(_ind,_root);
   if((_size)!=_ind)
      cout << "cos jest zle" << endl;
   return *this;
}


#endif
