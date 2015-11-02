#ifndef BIG_C_INT_H
#define BIG_C_INT_H

//  BIG_INT is meant to be immutable, only should 
// allow functions to make and change current 
// instances of the structure

struct BIG_INT {
   unsigned char* bytes;
   unsigned int    size;
};

void big_int_from_str(struct BIG_INT*, char*);
void big_int_from_int(struct BIG_INT*, int);
void big_int_from_uint(struct BIG_INT*, unsigned int);
void big_int_phex(struct BIG_INT*);

#endif
