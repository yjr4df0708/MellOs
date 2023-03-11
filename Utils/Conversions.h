#ifndef CONVERSIONS_H
#define CONVERSIONS_H
char *toString(int n, char *buf, int base);
void kprintInt(int n, int base);
int oct2bin(unsigned char *str, int size);
int hex2bin(unsigned char *str, int size);
#endif
