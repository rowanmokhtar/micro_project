#ifndef TYPES_H
#define TYPES_H

typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long long  u64;

typedef signed char         s8;
typedef signed short        s16;
typedef signed int          s32;
typedef signed long long    s64;

typedef float               f32;
typedef double              f64;

#define setBit(reg, bit)    ((reg) |=  (1 << (bit)))
#define clearBit(reg, bit)  ((reg) &= ~(1 << (bit)))
#define toggleBit(reg, bit) ((reg) ^=  (1 << (bit)))
#define readBit(reg, bit)   (((reg) >> (bit)) & 1)

#endif /* TYPES_H */