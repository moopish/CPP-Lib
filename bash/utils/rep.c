#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
   if (argc == 3) {
      int i;
      for (i=0; i<argc; ++i)
         printf("%s\n", argv[i]);
   }

   return (0);
}
