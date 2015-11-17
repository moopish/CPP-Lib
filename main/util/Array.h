#ifndef MSVD_ARRAY_H
#define MSVD_ARRAY_H

#include "sptr.h"

//TODO add checks

template< typename T >
class Array
{
   private :
      T*  array;
      int len;

   public :
      Array(int);
      Array(const Array<T>&);
      Array(int,T[]);
      ~Array();

      int length();

      T& operator[](int i);
        
};

template< typename T >
Array<T>::Array(int l)
{
   array = new T[l];
   len = l;
}

template< typename T >
Array<T>::Array(const Array<T>& o) : Array<T>(o.len)
{
   for (int i=0; i<len; ++i) {
      array[i] = o[i];
   }
}

template< typename T >
Array<T>::Array(int l, T* arr) : Array<T>(l)
{
   for (int i=0; i<l; ++i) {
      array[i] = arr[i];
   }
}

template< typename T >
Array<T>::~Array()
{
   delete [] array;
}

template< typename T >
int Array<T>::length()
{
   return (len);
}


template< typename T >
T& Array<T>::operator[](int i)
{
   return (array[i]);
}

#endif
