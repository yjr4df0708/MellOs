/*********************** FUNCTIONS ********************************
* reverse: reverses a string                                      *
* strLen: returns length of a string                              *
* StringsEqu: returns true if strings are equal (max len 80)      *
* StringStartsWith: returns true if s starts with t (max len 80)  *
******************************************************************/

//I moved format to the end because it's too big.

#include "../Memory/mem.h"
#include "../Drivers/VGA_Text.h"
#include "../Utils/Varargs.h"
//#include "../Utils/Math.h"

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

int is_c_alpha_lower(char c){
	return c<='z'&&c>='a';
}

int is_c_alpha_upper(char c){
	return c<='Z'&&c>='A';
}

int is_c_alpha(char c){
	return is_c_alpha_lower(c)||is_c_alpha_upper(c);
}

int is_c_numeric(char c){
	return c<='9'&&c>='0';
}

int is_c_alnumeric(char c){
	return is_c_alpha(c)||is_c_numeric(c);
}

int is_c_in_s(char c, char *s){
	for(int i=0;s[i];i++)
		if(s[i]==c)
			return 1;
	return 0;
}

int StringsEqu(const char* s, const char* t){
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
/*
char *format(char *buf, const char *fmt, ...){
	va_list l;
	va_start(l, fmt);
	int ii=0, oi=0;
	for(;fmt[ii];ii++)
		if(fmt[ii]=='%'){//a lot of these can be condensed into a bit-field or 2, most are just 1 or 2 bits
			if(fmt[ii+1]=='%'){
				ii++;
				goto exit;
			}
			struct{
				int padding:1;
				int width:1;
				int sign_space:1;
				int decor:1;
				int precision:1;
			} settings={0};
			int padding=0;//default: 0: no padding
			int width=0;
			int sign_space=0;
			int decor=0;
			int precision=1;
			unsigned short type=0;//first byte is length, second is base type
			int seg=0;//0:flags,1:width,2:precision,3:length,4:type
			for(int ii2=ii+1;fmt[ii2];ii2++){
				switch(fmt[ii2]){
					case '-':
						//belongs to flags
						if(seg>0||settings.padding)
							goto exit;
						padding=2;
						settings.padding=1;
						break;
					case '+':
						if(seg>0||settings.sign_space)
							goto exit;
						sign_space=1;
						settings.sign_space=1;
						break;
					case ' ':
						if(seg>0||settings.sign_space)
							goto exit;
						sign_space=2;
						settings.sign_space=1;
						break;
					case '#':
						if(seg>0||settings.decor)
							goto exit;
						decor=1;
						settings.decor=1;
						break;
					case '0':
						if(seg>0||settings.padding)
							goto exit;
						padding=3;
						settings.padding=1;
						break;
					case '*':
						if(seg>=1)//I hate these
							goto exit;
						settings.width=1;//marked for a possible argument later
						seg=1;
						break;
					case '.':
						if(seg>=2)
							goto exit;
						if(fmt[ii2+1]=='*')
							settings.precision=1;//marked for later arg
						else{
							while(is_c_numeric(fmt[ii2+1]))
								precision=precision*10+fmt[++ii2]-'0';
							if(!precision)
								goto exit;
						}
						seg=2;
						break;
					default:
						if(is_c_numeric(fmt[ii2])){
							if(seg>=1||settings.width)
								goto exit;
							do{
								width=width*10+fmt[ii2]-'0';
							}while(is_c_numeric(fmt[++ii2]));
							seg=1;
						}else{
							switch(fmt[ii2]){
								case 'h':case 'l':
									type=fmt[ii2+1]==fmt[ii2]<<8;
								case 'j':case 'z':case 't':case 'L':
									break;
								case 'd':
									type+='i';
									goto finish;
								case 'i':case 'u':case 'o':case 'x':case 'X':case 'f':case 'F':case 'g':case 'G':case 'a':case 'A':case 'c':case 's':case 'p':case 'n'://is this good or bad
									type+=fmt[ii2];
									goto finish;
								default:
									goto exit;
							}
							type+=fmt[ii2]<<8;
							if(seg>=3)
								goto exit;
							seg=4;
						break;
				}
			}
			va_list l_bak=l;//might want to reset the list
			finish:
			//woohoo, a problem: we need to ask for the width or precision first (because variable args), but we can't until we know the type is valid, so either
			//go through all the types and make sure they work
			//or just go against convention and ask for those possible args after (in calling format, pass the args in value first, then width and precision)
			//(or maybe do some fuckery with resetting the va_list to "peek" at args early, sure that seems like a good idea)
			//or just take the pointer and don't cast it yet
			if(settings.width)//width can be handled independantly of type
				width=va_arg(l, unsigned int);
			if(settings.precision)//precision cannot
				precision=va_arg(l, unsigned int);
			char buf[256]={0};
			switch(type){//this is how we're doing things, 31 case branches starting with near-identical functionality because of type differences
				case 0<<8+'i':
					int v=va_arg(l, int);
					int v2=v;
					int p=0;
					int len=precision<log2(v)/log2(10)?(int)(log2(v)/log2(10)):precision;//I don't think I can just use a builtin like this but sure
					int i=0;
					while(p++<precision||v2){
						buf[len-1-i++]=v2%10+'0';
						v2/=10;
					}
					break;
				case 0<<8+'u':
				
			}
			if(strLen(buf)<width)
			goto skip;
			exit:
			l=l_bak;//possibly reset va_list in case of syntax failure (not recognising the construction half-way through computation)
			buf[oi++]='%';
			skip:
		}else
			buf[oi++]=fmt[ii];
	return buf;
}*/