#ifndef MSVD_ARRAY_H
#define MSVD_ARRAY_H

template< typename T >
class Array
{
   private :
      T* array;
      int len;

   public :
      inline T& operator[](int i);
      
};

template< typename T >
inline T& Array<T>::operator[](int i)
{
   return (array[i]);
}

#endif
