#include "../../Drivers/VGA_Text.h"
#include "../Memory/mem.h"
#include "../Memory/cmos_memsize.h"
#include "../Utils/Conversions.h"
#include "../Utils/string.h"
#define FDEF(name) void name(const char* s)

FDEF(usedmem){
	kprint("Used dynamic memory: ");
	kprintInt(getFreeMem()-0x10000, 10);
	kprint(" bytes");
}


FDEF(meminfo){    
	kprint("meminfo:\n");
	kprint(" e820h:\n");
	mem_t mem = memget();
	kprint("  Lower memory: ");
//     kprint(toString(mem.lower_size, 10));
	kprintInt(mem.lower_size, 10);
	kprint(" KB\n");
	kprint("  Upper memory: ");
//     kprint(toString(mem.upper_size * 64, 10)); //mem.upper_size contains the size in 64K blocks
	kprintInt(mem.upper_size, 10);
	kprint(" KB\n");

	kprint("\n e801h:\n");
	mem = upper_memget();
	kprint("  Extended 1: ");
//     kprint(toString(mem.lower_size, 10));
	kprintInt(mem.lower_size, 10);

	kprint(" KB\n");
	kprint("  Extended 2: ");
	kprintInt(mem.upper_size * 64, 10);
//     kprint(toString(mem.upper_size * 64, 10)); //mem.upper_size contains the size in 64K blocks
	kprint(" KB\n");

	kprint("\n\nExtended 1 = Number of contiguous KB between 1 and 16 MB,");
	kprint("\n             maximum 0x3C00 = 15 MB");
	kprint("\n\nExtended 2 = Number of contiguous KB between 16 MB and 4 GB.");
}

FDEF(cmosmem){
	unsigned char mem_size = get_CMOS_memory_size();
	kprint("cmosmem:\n\t");
	kprintInt(mem_size, 10); //mem.upper_size contains the size in 64K blocks
	kprint(" KB\n");
}
