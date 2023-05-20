#include "../../Drivers/VGA_Text.h"
#include "../../Utils/string.h"
#define FDEF(name) void name(const char* s)

FDEF(hcf){
    int x = *((uint8_t*) 0xffffffff) = 1;
}

FDEF(test){
	char buf[128];
	kprint(format(buf, "\n(%p)\n", buf));
}