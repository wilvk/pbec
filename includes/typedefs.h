#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <cstdint>

typedef uint8_t BYTE;
typedef uint16_t WORD;
typedef uint32_t DWORD;

#define VRAM_TIMING_LATENCY_LENGTH 48
#define POWERPLAY_RESERVED_LENGTH 6
#define VRAM_ENTRY_MEM_PN_LENGTH 20
#define EXPECTED_FILE_SIZE_BYTES 524288
#define ATOM_ROM_HEADER_PTR 0x48
#define MAX_VRAM_ENTRIES 48

#endif /* end of include guard: TYPEDEFS_H */
