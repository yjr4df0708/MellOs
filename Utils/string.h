#ifndef STRING_H
#define STRING_H
#include "Typedefs.h"
char* reverse(char* str, char* buffer, int len);
int strLen(const char* s);
int is_c_alpha_lower(char c);
int is_c_alpha_upper(char c);
int is_c_alpha(char c);
int is_c_numeric(char c);
int is_c_alnumeric(char c);
bool StringsEqu(const char* s, const char* t);
bool StringStartsWith(const char* s, const char* t);
int strFindChar(const char* s, char c);
const char* strDecapitate(const char* s, int n);
#endif
