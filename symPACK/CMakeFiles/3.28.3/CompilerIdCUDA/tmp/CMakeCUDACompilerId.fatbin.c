#ifndef __SKIP_INTERNAL_FATBINARY_HEADERS
#include "fatbinary_section.h"
#endif
#define __CUDAFATBINSECTION  ".nvFatBinSegment"
#define __CUDAFATBINDATASECTION  ".nv_fatbin"
asm(
".section .nv_fatbin, \"a\"\n"
".align 8\n"
"fatbinData:\n"
".quad 0x00100001ba55ed50,0x0000000000000308,0x0000004001010002,0x0000000000000248\n"
".quad 0x0000000000000000,0x0000003400010007,0x0000000000000000,0x0000000000000011\n"
".quad 0x0000000000000000,0x0000000000000000,0x33010102464c457f,0x0000000000000007\n"
".quad 0x0000007800be0002,0x0000000000000000,0x00000000000001d8,0x00000000000000d8\n"
".quad 0x0038004000340534,0x0001000400400002,0x7472747368732e00,0x747274732e006261\n"
".quad 0x746d79732e006261,0x746d79732e006261,0x78646e68735f6261,0x7466752e766e2e00\n"
".quad 0x2e007972746e652e,0x006f666e692e766e,0x7472747368732e00,0x747274732e006261\n"
".quad 0x746d79732e006261,0x746d79732e006261,0x78646e68735f6261,0x7466752e766e2e00\n"
".quad 0x2e007972746e652e,0x006f666e692e766e,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000300000001,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000040,0x0000000000000040,0x0000000000000000,0x0000000000000001\n"
".quad 0x0000000000000000,0x000000030000000b,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000080,0x0000000000000040,0x0000000000000000,0x0000000000000001\n"
".quad 0x0000000000000000,0x0000000200000013,0x0000000000000000,0x0000000000000000\n"
".quad 0x00000000000000c0,0x0000000000000018,0x0000000100000002,0x0000000000000008\n"
".quad 0x0000000000000018,0x0000000500000006,0x00000000000001d8,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000070,0x0000000000000070,0x0000000000000008\n"
".quad 0x0000000500000001,0x00000000000001d8,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000070,0x0000000000000070,0x0000000000000008,0x0000004801010001\n"
".quad 0x0000000000000038,0x0000004000000036,0x0000003400080000,0x0000000000000000\n"
".quad 0x0000000000002011,0x0000000000000000,0x0000000000000038,0x0000000000000000\n"
".quad 0x762e21f000010a13,0x38206e6f69737265,0x677261742e0a302e,0x32355f6d73207465\n"
".quad 0x7365726464612e0a, 0x3620657a69735f73, 0x0000000a0a0a0a34\n"
".text\n");
#ifdef __cplusplus
extern "C" {
#endif
extern const unsigned long long fatbinData[99];
#ifdef __cplusplus
}
#endif
#ifdef __cplusplus
extern "C" {
#endif
static const __fatBinC_Wrapper_t __fatDeviceText __attribute__ ((aligned (8))) __attribute__ ((section (__CUDAFATBINSECTION)))= 
	{ 0x466243b1, 1, fatbinData, 0 };
#ifdef __cplusplus
}
#endif
