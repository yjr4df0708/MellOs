#include "../../Drivers/VGA_Text.h"
#include "../../Utils/Conversions.h"
#include "../../Utils/Math.h"
#define FDEF(name) void name(const char* s)

FDEF(hcf){
    int x = *((uint8_t*) 0xffffffff) = 1;
}

FDEF(test){
	kprint("log10(607)=");
	kprintInt(log(607, 10), 10);
}