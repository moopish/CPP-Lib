#ifndef MSVD_EMEXP_BOOLEAN_H
#define MSVD_EMEXP_BOOLEAN_H

#include "Type.h"

class Boolean : public Type
{
   private :
      bool value;

   public :
      virtual EmExpType evalTo();

      

};

#endif
