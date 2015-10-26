#include "cont/ArrayList.h"

#include <iostream>

int main(int argc, char** argv)
{
   ArrayList<int> test;

   for (int i=0; i<64; ++i) {
      test.add(i/2, new int(i));
      for (int j=0; j<test.size(); ++j) {
         std::cout << *test.get(j) << " ";
      }
      std::cout << std::endl;
   }

   for (int i=0; i<64; ++i) {
      delete test.remove(0);
      for (int j=0; j<test.size(); ++j) {
         std::cout << *test.get(j) << " ";
      }
      std::cout << std::endl;
   }

   return (0);
}
