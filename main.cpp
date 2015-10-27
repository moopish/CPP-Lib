#include "cont/list/ArrayList.h"

#include <iostream>
#include <cstdlib>

int main(int argc, char** argv)
{
   ArrayList<int> test;

   for (int i=0; i<1000; ++i) {
      test.add(rand() % (i + 1), new int(i));
   }

   while (!test.empty()) {
      delete test.remove(rand() % test.size());
   }

   return (0);
}
