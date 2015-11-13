#ifndef MSVD_EMEXP_H
#define MSVD_EMEXP_H

/*
 * EMEXP FOR C++
 * * * * * * * * * * 
   * BY: Michael van Dyk
   *
   *   EmExp is meant to be an evaluator of 
   *  boolean and arithmetic statements.
   *
   */

enum EmExpType { BOOL, INT, NULL, EXP };

class EmExp 
{
   private :

   public :
      virtual EmExp& eval() = 0;
      virtual EmExpType evalTo();
};

#endif
