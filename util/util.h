#ifndef UTIL_H
#define UTIL_H

#define GET_BIT_FAIL 2

typedef unsigned char uchar;
typedef unsigned int   uint;
typedef unsigned long ulong;

inline uchar clrbit(uchar, int);
inline uchar getbit(uchar, int);
inline uchar setbit(uchar, int);

inline uint i_clrbit(uint, int);
inline uint i_getbit(uint, int);
inline uint i_setbit(uint, int);

struct _int_qll {
   int value;
   struct _int_qll* next;
};

struct _int_qll* _int_qll_init(int);
struct _int_qll* _int_qll_add(struct _int_qll*, int);
struct _int_qll* _int_qll_rem(struct _int_qll*);

#endif
