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
      T*   data;  // The address of the data
      int* count; // The number of pointers to the address

   public :
    /*
     * Related to construction/destruction
     * * * * * * * * * * * * * * * * * * * */
      SmartPointer();
      SmartPointer(const SmartPointer<T>&);
      SmartPointer(const T&);
      SmartPointer(T* const);
      ~SmartPointer();

    /*
     * Assignment and Unassignment
     * * * * * * * * * * * * * * * */
      void assign(const SmartPointer<T>&);
      void assign(const T&);
      void assign(T* const);
      void clear();

    /*
     * Assignment/Unassignment Operators
     * * * * * * * * * * * * * * * * * * */
      SmartPointer<T>& operator=(const SmartPointer<T>&); // Assignment by another sptr
      SmartPointer<T>& operator=(T* const);               // Assignment by data pointer
      SmartPointer<T>& operator=(const T&);               // Assignment by data reference
      SmartPointer<T>& operator-();                       // Clear operator
     
    /*
     * Member Operators
     * * * * * * * * * * */
      T& operator*();     // Deref
      T* operator->();    // Use member of data
      //T& operator[](int); // Subscript (allows for arrays)

    /*
     * Relational Operators
     * * * * * * * * * * * * */
      bool operator==(const SmartPointer<T>&); // Equivalence operator
      bool operator!=(const SmartPointer<T>&); // Non-Equivalence operator
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
         delete [] data;
         delete count;
         data = 0;
         count = 0;
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
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer<T>& o)
{
   assign(o);
   return (*this);
}

template< typename T >
SmartPointer<T>& SmartPointer<T>::operator=(T* const o)
{
   assign(o);
   return (*this);
}

template< typename T >
SmartPointer<T>& SmartPointer<T>::operator=(const T& o)
{
   assign(o);
   return (*this);
}

template< typename T >
SmartPointer<T>& SmartPointer<T>::operator-()
{
   clear();
   return (*this);
}

template< typename T >
T& SmartPointer<T>::operator*()
{
   return (*data);
}

template< typename T >
T* SmartPointer<T>::operator->()
{
   return (data);
}

//template< typename T >
//T& SmartPointer<T>::operator[](int index)
//{
//   return (data[index]);
//}

template< typename T >
bool SmartPointer<T>::operator==(const SmartPointer<T>& o)
{
   return (data == o.data);
}

template< typename T >     
bool SmartPointer<T>::operator!=(const SmartPointer<T>& o)
{
   return (!(*this == o));
}  

#endif
