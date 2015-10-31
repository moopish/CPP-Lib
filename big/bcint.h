#ifndef BIG_C_INT_H
#define BIG_C_INT_H

//  BIG_UINT is meant to be immutable, only should 
// allow functions to make and change current 
// instances of the structure

struct BIG_UINT {
   unsigned char* bytes;
   unsigned int    size;
};

typedef struct BIG_UINT bigUInt;

void big_uint_init(struct BIG_UINT*, unsigned int);
void big_uint_phex(struct BIG_UINT*);

#endif