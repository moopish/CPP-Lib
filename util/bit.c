#include "util.h"

#define B_CHECK(B, T) ((B) < 0 || (B) >= sizeof(T) * 8)

inline uchar clrbit(uchar n, int b) 
{
   if B_CHECK(b, uchar)
      return (n);
   return (n & ~(1<<b));
}

inline uchar getbit(uchar n, int b)
{
   if B_CHECK(b, uchar)
      return (GET_BIT_FAIL);
   return ((n>>b)&1);
}

inline uchar setbit(uchar n, int b)
{
   if B_CHECK(b, uchar)
      return (n);
   return (n | (1<<b));
}

inline uint i_clrbit(uint n, int b) 
{
   if B_CHECK(b, uint)
      return (n);
   return (n & ~(1<<b));
}

inline uint i_getbit(uint n, int b)
{
   if B_CHECK(b, uint)
      return (GET_BIT_FAIL);
   return ((n>>b)&1);
}

inline uint i_setbit(uint n, int b)
{
   if B_CHECK(b, uint)
      return (n);
   return (n | (1<<b));
}
