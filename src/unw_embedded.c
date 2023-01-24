#include <stdint.h>

#include <elf.h>
#include <link.h>

extern uint8_t __text_region_start[];
extern uint8_t __text_region_end[];
extern uint8_t __eh_frame_hdr_region_start[];
extern uint8_t __eh_frame_hdr_region_end[];

#if __SIZE_WIDTH__ == 32
typedef Elf32_Phdr Phdr;
#elif __SIZE_WIDTH__ == 64
typedef Elf64_Phdr Phdr;
#else
#error "Can't determine ELF width."
#endif

#define PHNUM 2

int dl_iterate_phdr(int(*callback)(struct dl_phdr_info*, size_t, void*), void* data) {
  Phdr phdrs[PHNUM] = {};
  struct dl_phdr_info phdr_info;
  phdr_info.dlpi_addr = 0;
  phdr_info.dlpi_name = "zephyr";
  phdr_info.dlpi_phdr = phdrs;
  phdr_info.dlpi_phnum = sizeof(phdrs) / sizeof(phdrs[0]);
  // phdrs[0] is text section.
  phdrs[0].p_type = PT_LOAD;
  phdrs[0].p_vaddr = __text_region_start;
  phdrs[0].p_filesz = __text_region_end - __text_region_start;
  phdrs[0].p_memsz = __text_region_end - __text_region_start;
  // XXX check size
  // phdrs[1] is eh_frame_hdr section.
  //phdrs[1].p_type = PT_GNU_EH_FRAME;
  //phdrs[1].p_vaddr = __eh_frame_hdr_region_start;
  //phdrs[1].p_filesz = __eh_frame_hdr_region_end - __eh_frame_hdr_region_start;
  //phdrs[1].p_memsz = __eh_frame_hdr_region_end - __eh_frame_hdr_region_start;

  int cb_ret = callback(&phdr_info, sizeof(phdr_info), data);
  return cb_ret;
}
