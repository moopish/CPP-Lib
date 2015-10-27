#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <algorithm>

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

      void resize(int);

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
      resize(len << 1);
   }

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
      resize(((len >> 1) < 1) ? 1 : (len >> 1));
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
void ArrayList<E>::resize(int new_len)
{
   E** new_arr = new E*[new_len];

   if (len < pos + ems) {
      std::copy(arr + pos, arr + len, new_arr);
      std::copy(arr, arr + (pos + ems - len), new_arr + (len - pos));
   } else {
      std::copy(arr + pos, arr + pos + ems, new_arr);
   }

   len = new_len;
   pos = 0;
   delete [] arr;
   arr = new_arr;
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
