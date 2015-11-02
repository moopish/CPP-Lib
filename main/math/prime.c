#include "math.h"
#include "../util/util.h"

#include <stdlib.h>

int prime(int n)
{
   if (n <= 1) return (0);
   return (0);
}

int gen_primes(int n, int** primes)
{
   int length = (int)(n/8);
   int count = 1;
   if ((float)length < n/8.0f)
      ++length;
   uchar checks[length];
   
   int i=0, j, temp;
   for (; i<length; ++i) {
      checks[i] = ~'\0';
   }
   
   i=2;
   
   while (i <= n/i) {
      for (j=2; j<=n/i; ++j) {
         temp = j * i / 8;
         checks[temp] = clrbit(checks[temp], j * i - temp * 8);
      }
      
      do {
        ++i;
        temp = i / 8;
      } while (!getbit(checks[temp], i - temp * 8));
   }
   
   struct _int_qll *head, *tail;
   head = tail = _int_qll_init(2);
   
   for (i=2; i<n; ++i) {
      temp = i / 8;
      if (getbit(checks[temp], i - temp * 8)) {
         ++count;
         tail;
      }
   }
} 