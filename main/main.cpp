#include "arr/Array.h"

#include "big/bcint.h"
#include "util/util.h"
#include "math/math.h"

#include "util/sptr.h"

#include <iostream>

int main()
{
   int i = 5;
   sptr<int> a;
   a.assign(i);

   sptr<int> b(new int(7));
 
   return (0);  
}

