#include "util/Array.h"

#include "big/bcint.h"
#include "util/util.h"
#include "math/math.h"

#include "util/sptr.h"

#include <iostream>

using namespace std;

struct int_temp {
   int x;
};

int main()
{
   sptr< Array<int> > test(new Array<int>(5));

   cout << test->length() << endl;
 
   return (0);  
}

