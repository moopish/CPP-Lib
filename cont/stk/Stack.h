#ifndef STACK_H
#define STACK_H

template< typename E >
class Stack
{
   public :
      virtual bool push(E* item) = 0;
};

#endif
