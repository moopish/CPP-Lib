#include "util.h"

#define B_CHECK(B, T) ((B) < 0 || (B) >= sizeof(T) * 8)

uchar clrbit(uchar n, int b) 
{
   if B_CHECK(b, uchar)
      return (n);
   return (n & ~(1<<b));
}

uchar getbit(uchar n, int b)
{
   if B_CHECK(b, uchar)
      return (GET_BIT_FAIL);
   return ((n>>b)&1);
}

uchar setbit(uchar n, int b)
{
   if B_CHECK(b, uchar)
      return (n);
   return (n | (1<<b));
}
