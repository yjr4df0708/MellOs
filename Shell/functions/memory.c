#include "../../Drivers/VGA_Text.h"
#include "../Memory/shmalloc.h"
#include "../Memory/mem.h"
#include "../Memory/cmos_memsize.h"
#include "../Utils/Conversions.h"
#include "../Utils/string.h"
#include "../Utils/Math.h"
#define FDEF(name) void name(const char* s)

FDEF(usedmem){
    kprint("Used dynamic memory: ");
    kprintInt(getFreeMem()-0x10000, 10);
    kprint(" bytes");
}

FDEF(meminfo){
    mem_t mem=memget();
    char buf[2][128];
    kprintVA(5, "meminfo:\nLower memory: \n", toString(mem.lower_size, buf[0], 10), " KB\nUpper memory: \n", toString(mem.upper_size * 64, buf[1], 10), " KB\n");
    //mem.upper_size contains the size in 64K blocks
}

FDEF(cmosmem){
    unsigned char mem_size = get_CMOS_memory_size();
    kprint("cmosmem:\n\t");
    kprintInt(mem_size, 10); //mem.upper_size contains the size in 64K blocks
    kprint(" KB\n");
}
