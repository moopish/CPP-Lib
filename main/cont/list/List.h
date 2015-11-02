#ifndef LIST_H
#define LIST_H

template< typename E >
class List
{
   public :
      List();
      ~List();
 
      virtual List<E>& add(int, E*) = 0;
      virtual E* get(int) = 0;
      virtual E* remove(int) = 0;
      virtual E* set(int, E*) = 0;

      bool empty();
      virtual int size() = 0;
};

template< typename E >
List<E>::List() { }

template< typename E >
List<E>::~List() { }

template< typename E >
bool List<E>::empty()
{
   return (size() == 0);
}

#endif
