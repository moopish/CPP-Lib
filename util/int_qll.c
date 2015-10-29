#include "util.h"

#include <stdlib.h>

inline struct _int_qll* _int_qll_init(int value)
{
   struct _int_qll* init = (struct _int_qll*)malloc(sizeof(struct _int_qll*));
   init->value = value;
   init->next = 0;
   return (init);
}

inline struct _int_qll* _int_qll_add(struct _int_qll* qll, int value)
{
   return (qll->next = _int_qll_init(value));
}

inline struct _int_qll* _int_qll_rem(struct _int_qll* qll)
{
   struct _int_qll* ret = qll->next;
   free(qll);
   return (ret);
}