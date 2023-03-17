#ifndef TYPEDEF_H
#define TYPEDEF_H

typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned short uint16_t;
typedef signed short int16_t;
typedef unsigned int uint32_t;
typedef signed int int32_t;
typedef uint32_t size_t;
typedef uint32_t uintmax_t;
typedef int32_t intmax_t;
typedef uint32_t uintptr_t;
typedef int32_t ptrdiff_t;

//basic functions for int64 are only somewhat supported by the compiler
//it may try to link __divdi3 or similar functions, but will fail
typedef unsigned long long uint64_t;
typedef signed long long int64_t;

typedef uint8_t bool;
#define true    1
#define false   0

#define low_16(address) (uint16_t)((address) & 0xFFFF)
#define high_16(address) (uint16_t)((address) >> 16)
#define low_8(address) (uint8_t)((address) &  0xFF)
#define high_8(address) (uint8_t)((address) >> 8)

#endif
