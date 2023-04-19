//"Software version 7.0"


/*********************** FUNCTIONS *************************
* 							     *
* toString: converts int into string - arbitrary base      *
* 							     *
***********************************************************/

#include "../Utils/string.h"
#include "../Drivers/VGA_Text.h"
#include "../Utils/Math.h"
#include "../Utils/Typedefs.h"

char *toString(int n, char *buf, int base){
	int m=n<0?-n:n;
	int i=0;
	unsigned int len=log(m, base)+1;//why does this need to be unsigned
	if(!len)
		len=1;
	if(n<0){
		len++;
		buf[0]='-';
	}
	do{
		buf[len-1-i++]=(char)(m%base+(m%base>9?55:'0'));
		m/=base;
	}while(m);
	buf[len]=0;
	return buf;
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
