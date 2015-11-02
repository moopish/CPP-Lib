#include "bcint.h"

#include <stdlib.h>
#include <stdio.h>

void big_int_from_uint(struct BIG_INT* bint, unsigned int init)
{
   bint->size = sizeof(unsigned int) / sizeof(unsigned char);
   bint->bytes = (unsigned char*)malloc(bint->size);
   
   int byte;
   for (byte = 0; byte < 4; ++byte) {
      bint->bytes[byte] = (unsigned char)(init >> (byte * 8));
   }
}

void big_int_phex(struct BIG_INT* bint)
{
   int i;
   for (i = bint->size - 1; i >= 0; --i) {
      printf("%x02 ", bint->bytes[i]);
   }
   printf("\n");
}
