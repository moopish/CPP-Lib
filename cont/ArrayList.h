#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "List.h"

//ARRAY IMPLEMENTED AS ARRAY DEQUE
//WILL BREAK IF ADD MAX INT ELEMS
template< typename E >
class ArrayList : public List<E>
{
   private :
      int ems;
      int pos;
      int len; // MUST BE A POWER OF TWO
      E** arr;

   public :
      ArrayList();
      ~ArrayList();

      virtual List<E>& add(int, E*);
      virtual E* get(int);
      virtual E* remove(int);
      virtual E* set(int, E*);

      virtual int size();
};

template< typename E >
ArrayList<E>::ArrayList()
{
   ems = pos = 0;
   len = 1;
   arr = new E*[1];
}

template< typename E >
ArrayList<E>::~ArrayList()
{
   delete [] arr;
}

template< typename E >
List<E>& ArrayList<E>::add(int index, E* item)
{
   if (ems + 1 > len) {
      int new_len = len << 1;
      E** new_arr = new E*[new_len];

      int k;
      for (k=0; k<index; ++k) {
         new_arr[k] = arr[(pos + k) & (len - 1)];
      }

      new_arr[index] = item;

      for (; k<ems; ++k) {
         new_arr[k + 1] = arr[(pos + k) & (len - 1)];
      }
 
      len = new_len;
      pos = 0;
      delete [] arr;
      arr = new_arr;
   } else {
      if (index < ems/2) {
         pos = (pos == 0) ? len - 1 : pos - 1;
         for (int k = 0; k <= index - 1; ++k) {
            arr[(pos + k) & (len - 1)] = arr[(pos + k + 1) & (len - 1)];
         }
      } else {
         for (int k = ems; k > index; --k) {
            arr[(pos + k) & (len - 1)] = arr[(pos + k - 1) & (len - 1)];
         }
      }
      arr[(pos + index) & (len - 1)] = item;
   }

   ++ems;
   return (*this);
}

template< typename E >
E* ArrayList<E>::get(int index)
{
   return (arr[(pos + index) & (len - 1)]);
}

template< typename E >
E* ArrayList<E>::remove(int index)
{
   E* ret = arr[(pos + index) & (len - 1)];

   if (ems*4 < len) {
      int new_len = len >> 1;
      if (new_len < 1) new_len = 1;

      E** new_arr = new E*[new_len];

      for (int l = 0; l < ems; ++l) {
         new_arr[l] = arr[(pos + l) & (len - 1)];
      }

      len = new_len;
      pos = 0;
      delete [] arr;
      arr = new_arr;
   } 

   if (index < ems/2) {
      for (int k = index; k > 0; --k) {
         arr[(pos + k) & (len - 1)] = arr[(pos + k - 1) & (len - 1)];
      }
      pos = (pos + 1) & (len - 1);
   } else {
      for (int k = index; k < ems - 1; ++k) {
         arr[(pos + k) & (len - 1)] = arr[(pos + k + 1) & (len - 1)];
      }
   }

   --ems;
   return (ret);
}

template< typename E >
E* ArrayList<E>::set(int index, E* item)
{
   E* ret = arr[(pos + index) & (len - 1)];
   arr[(pos + index) & (len - 1)] = item;
   return (ret);
}

template< typename E >
int ArrayList<E>::size()
{
   return (ems);
}

#endif
