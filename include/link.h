#pragma once

#include <stddef.h>
#include <stdint.h>
//#define ElfW(type)	_ElfW (Elf, __ELF_NATIVE_CLASS, type)
//#define _ElfW(e,w,t)	_ElfW_1 (e, w, _##t)
//#define _ElfW_1(e,w,t)	e##w##t

struct dl_phdr_info {
  uintptr_t dlpi_addr;
  const char *dlpi_name;
  const void* dlpi_phdr;
  uint16_t dlpi_phnum;
};

int dl_iterate_phdr(int(*)(struct dl_phdr_info*, size_t, void*), void*);
