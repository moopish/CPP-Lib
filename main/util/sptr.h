#ifndef MSVD_SPTR_H
#define MSVD_SPTR_H

#define sptr SmartPointer

/*
 * SmartPointer 
 * By: Michael van Dyk
 * * * * * * * * 
   *    A class to control the allocation and 
   *  deallocation of pointers.
   */
template< typename T >
class SmartPointer
{
   private :
      T*   data;
      int* count;

   public :
      SmartPointer();
      SmartPointer(const SmartPointer<T>&);
      SmartPointer(const T&);
      SmartPointer(T* const);
      ~SmartPointer();

      void assign(const SmartPointer<T>&);
      void assign(const T&);
      void assign(T* const);
      void clear();

      inline SmartPointer<T>& operator=(const SmartPointer<T>&);
      inline SmartPointer<T>& operator=(T* const);
      inline SmartPointer<T>& operator=(const T&);
      inline SmartPointer<T>& operator-();
     
      inline T& operator*();

      inline bool operator==(const SmartPointer<T>&);
      inline bool operator!=(const SmartPointer<T>&); 
};

template< typename T >
SmartPointer<T>::SmartPointer() : data(0), count(0) { }

template< typename T >
SmartPointer<T>::SmartPointer(const SmartPointer& o)
{
   data = o.data;
   count = o.count;
   if (count)
      ++(*count);
}

template< typename T >
SmartPointer<T>::SmartPointer(const T& o)
{
   assign(o);
}

template< typename T >
SmartPointer<T>::SmartPointer(T* const o)
{
   assign(o);
}

template< typename T >
SmartPointer<T>::~SmartPointer()
{
   clear();
}

template< typename T >
void SmartPointer<T>::clear()
{
   if (count) {
      --(*count);
      if (*count == 0) {
         delete data;
         delete count;
         data = count = 0;
      }
   }
}

template< typename T >
void SmartPointer<T>::assign(const SmartPointer<T>& o)
{
   clear();
   data = o.data;
   count = o.count;
   if (count)
      ++(*count);   
}

template< typename T >
void SmartPointer<T>::assign(const T& o)
{
   data = new T(o);
   count = new int(1);
}

template< typename T >
void SmartPointer<T>::assign(T* const o)
{
   data = o;
   count = new int(1);
}

template< typename T >
inline SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer<T>& o)
{
   assign(o);
   return (*this);
}

template< typename T >
inline SmartPointer<T>& SmartPointer<T>::operator=(T* const o)
{
   assign(o);
   return (*this);
}

template< typename T >
inline SmartPointer<T>& SmartPointer<T>::operator=(const T& o)
{
   assign(o);
   return (*this);
}

template< typename T >
inline SmartPointer<T>& SmartPointer<T>::operator-()
{
   clear();
   return (*this);
}

template< typename T >
inline T& SmartPointer<T>::operator*()
{
   return (*data);
}

template< typename T >
inline bool SmartPointer<T>::operator==(const SmartPointer<T>& o)
{
   return (data == o.data);
}

template< typename T >     
inline bool SmartPointer<T>::operator!=(const SmartPointer<T>& o)
{
   return (!(*this == o));
}  

#endif
