#include "big/bcint.h"

int main()
{
   bigUInt test;
   big_uint_init(&test, 1234);
   
   big_uint_phex(&test);

   return (0);
}

