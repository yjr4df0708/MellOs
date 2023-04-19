/*********************** FUNCTIONS ********************************
* reverse: reverses a string                                      *
* strLen: returns length of a string                              *
* StringsEqu: returns true if strings are equal (max len 80)      *
* StringStartsWith: returns true if s starts with t (max len 80)  *
******************************************************************/

//I moved format to the end because it's too big.

#include "../Memory/mem.h"
#include "../Drivers/VGA_Text.h"
#include "../Utils/Typedefs.h"
#include "../Utils/string.h"

//not a dependency, just fits better to this file but it's large enough for its own
#include "../Utils/format.h"

char *reverse(char *str, char *buffer, int len){
	int i=0;
	for(;i<len;i++)
		buffer[i]=str[len-1-i];
	buffer[i]='\0';
	return buffer;
}

int strLen(const char* s){
	int res;
	for(res=0;s[res];res++);
	return res;
}

bool is_c_alpha_lower(char c){
	return c<='z'&&c>='a';
}

bool is_c_alpha_upper(char c){
	return c<='Z'&&c>='A';
}

bool is_c_alpha(char c){
	return is_c_alpha_lower(c)||is_c_alpha_upper(c);
}

bool is_c_numeric(char c){
	return c<='9'&&c>='0';
}

bool is_c_alnumeric(char c){
	return is_c_alpha(c)||is_c_numeric(c);
}

bool is_c_in_s(char c, char *s){
	for(int i=0;s[i];i++)
		if(s[i]==c)
			return 1;
	return 0;
}

bool StringsEqu(const char* s, const char* t){
	const char* g = strLen(s) > strLen(t)? s : t;
	
	bool res = true;
	int i = 0;
	do{
		if(s[i] != t[i] || i > 80){
			res = false;
			break;
		}
		else i++;
	}while(g[i] != 0);
	return res;
}

bool StringStartsWith(const char* s, const char* t){
    const char* g = t;
	
	bool res = true;
	int i = 0;
	do{
		if(s[i] != t[i] || i > 80){
			res = false;
			break;
		}
		else i++;
	}while(g[i] != 0);
	return res;
    
}

int strFindChar(const char* s, char c){
    int i = 0;
	do{
		if(s[i] == c || i > 80){
			break;
		}
		else i++;
	}while(s[i] != 0);
    return(s[i] == 0 || i > 80 ? -1 : i);
}


const char* strDecapitate(const char* s, int n){            // Uses Dynamic Memory Allocation, be careful.
    int newLen = strLen(s) - n;
    if(newLen <= 0) return ""; 
    char* t = (char*)kmalloc(sizeof(char) * (newLen + 1));
    for(int i = 0; i < newLen; i++)
        t[i] = s[i + n];
    return t;
}