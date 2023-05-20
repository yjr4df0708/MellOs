#ifndef CONVERSIONS_H
#define CONVERSIONS_H
#include "../Utils/format.h"
//so you don't have to include it separately
char *reverse(char *str, char *buffer, int len);
char *toString(int n, char *buf, int base);
void kprintInt(int n, int base);
int oct2bin(unsigned char *str, int size);
int hex2bin(unsigned char *str, int size);
#endif
