//"Software version 7.0"


/*********************** FUNCTIONS *************************
* 							     *
* toString: converts int into string - arbitrary base      *
* 							     *
***********************************************************/

#include "string.h"
#include "../Drivers/VGA_Text.h"

char *toString(int n, char *buf, int base){
	char buf2[128];
	int m=n<0?-n:n;
	int i=0;
	do{
		buf2[i++]=(char)(m%base+(m%base>9?55:'0'));
		m/=base;
	}while(m);
	if(n<0)
		buf2[i++]='-';
	return reverse(buf2, buf, i);
}

void kprintInt(int n, int base){
	char buffer[128];
	kprint(toString(n, buffer, base));
	return;
}	

int oct2bin(unsigned char *str, int size) {
    int n = 0;
    unsigned char *c = str;
    while (size-- > 0) {
        n *= 8;
        n += *c - '0';
        c++;
    }
    return n;
}

int hex2bin(unsigned char *str, int size) {
    int n = 0;
    unsigned char *c = str;
    while(size-- > 0) {
        n *= 16;
        if(n >= '0' && n <= '9') n += *c - '0';
        else if (n >= 'A' && n <= 'F') n += *c - 55;
        c++;
    }
    return n;
}
