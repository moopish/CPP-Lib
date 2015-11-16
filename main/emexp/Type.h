#ifndef MSVD_EMEXP_TYPE_H
#define MSVD_EMEXP_TYPE_H

#include "EmExp.h"

class Type : public EmExp
{

   public : 
      virtual EmExp& eval();
      virtual EmExpType evalTo() = 0;

};

#endif
