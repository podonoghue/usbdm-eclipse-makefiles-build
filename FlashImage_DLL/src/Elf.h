/*
 * elf.h
 *
 *  Created on: 17/04/2012
 *      Author: podonoghue
 */

#ifndef ELF_H_
#define ELF_H_

#include <stdint.h>

//
#define EI_NIDENT        (16) // Size of e_ident field
#define EI_DATA          (5)  // Index of EI_DATA in e_indent field
#define EI_MAG0          (0)  // Magic number to identify ELF file
#define EI_MAG1          (1)
#define EI_MAG2          (2)
#define EI_MAG3          (3)
#define EI_CLASS         (4)  // File class
#define EI_DATA          (5)  // Data encoding

// e_ident[EI_MAG0..EI_MAG3]
#define ELFMAG0V         (0x7f)
#define ELFMAG1V         ('E')
#define ELFMAG2V         ('L')
#define ELFMAG3V         ('F')

// e_ident[EI_CLASS] values
#define ELFCLASSNONE     (0)  // Invalid class
#define ELFCLASS32       (1)  // 32-bit objects
#define ELFCLASS64       (2)  // 64-bit objects

// e_ident[EI_DATA] values
#define ELFDATANONE      (0)  // Invalid
#define ELFDATA2LSB      (1)  // Little-endian
#define ELFDATA2MSB      (2)  // Big-endian

#define ET_EXEC          (2)

#define EM_ARM     (40)
#define EM_68K     (04)
#define EM_68HC05  (72)
#define EM_68HC08  (71)
#define EM_68HC11  (70)
#define EM_68HC12  (53)
#define EM_68HC16  (69)
#define EM_56K_2   (0xC8)
#define EM_56K     (0x5670)
#define EM_S12X    (0x4DEF)


typedef uint32_t Elf32_Addr;  // Unsigned program address
typedef uint16_t Elf32_Half;  // Unsigned medium integer
typedef uint32_t Elf32_Off;   // Unsigned file offset
typedef int32_t  Elf32_Sword; // Signed integer
typedef uint32_t Elf32_Word;  // Unsigned integer

typedef struct {
   unsigned char   e_ident[EI_NIDENT];
   Elf32_Half      e_type;
   Elf32_Half      e_machine;
   Elf32_Word      e_version;
   Elf32_Addr      e_entry;
   Elf32_Off       e_phoff;
   Elf32_Off       e_shoff;
   Elf32_Word      e_flags;
   Elf32_Half      e_ehsize;
   Elf32_Half      e_phentsize;
   Elf32_Half      e_phnum;
   Elf32_Half      e_shentsize;
   Elf32_Half      e_shnum;
   Elf32_Half      e_shstrndx;
} Elf32_Ehdr;

#define PF_X (1<<0) // Execute
#define PF_W (1<<1) // Write
#define PF_R (1<<2) // Read

typedef struct {
   Elf32_Word p_type;
   Elf32_Off  p_offset;
   Elf32_Addr p_vaddr;
   Elf32_Addr p_paddr;
   Elf32_Word p_filesz;
   Elf32_Word p_memsz;
   Elf32_Word p_flags;
   Elf32_Word p_align;
} Elf32_Phdr;

#define PT_NULL      0
#define PT_LOAD      1
#define PT_DYNAMIC   2
#define PT_INTERP    3
#define PT_NOTE      4
#define PT_SHLIB     5
#define PT_PHDR      6

#define PT_ARM_ARCHEXT    0x70000000  // Platform architecture compatibility information
#define PT_ARM_EXIDX      0x70000001  // Exception
#define PT_ARM_UNWIND     0x70000001  // Unwind

typedef struct{
   Elf32_Word sh_name;
   Elf32_Word sh_type;
   Elf32_Word sh_flags;
   Elf32_Addr sh_addr;
   Elf32_Off  sh_offset;
   Elf32_Word sh_size;
   Elf32_Word sh_link;
   Elf32_Word sh_info;
   Elf32_Word sh_addralign;
   Elf32_Word sh_entsize;
} Elf32_Shdr;

// shtype values
#define SHT_NULL           0
#define SHT_PROGBITS       1
#define SHT_SYMTAB         2
#define SHT_STRTAB         3
#define SHT_RELA           4
#define SHT_HASH           5
#define SHT_DYNAMIC        6
#define SHT_NOTE           7
#define SHT_NOBITS         8
#define SHT_REL            9
#define SHT_SHLIB          10
#define SHT_DYNSYM         11
#define SHT_0x0C           12
#define SHT_0x0D           13
#define SHT_INIT_ARRAY     14
#define SHT_FINI_ARRAY     15
#define SHT_PREINIT_ARRAY  16

#define SHT_ARM_EXIDX            0x70000001  // Exception Index table
#define SHT_ARM_PREEMPTMAP       0x70000002  // BPABI DLL dynamic linking pre-emption map
#define SHT_ARM_ATTRIBUTES       0x70000003  // Object file compatibility attributes
#define SHT_ARM_DEBUGOVERLAY     0x70000004  // See DBGOVL for details
#define SHT_ARM_OVERLAYSECTION   0x70000005  //

#define SHT_PROC_SPECIFIC  0xF0000000

#define SHT_LOPROC      0x70000000
#define SHT_HIPROC      0x7fffffff
#define SHT_LOUSER      0x80000000
#define SHT_HIUSER      0xffffffff

#define SHF_WRITE       0x1
#define SHF_ALLOC       0x2
#define SHF_EXECINSTR   0x4
#define SHF_MASKPROC    0xf0000000

#define SHN_UNDEF       0

#endif /* ELF_H_ */
