#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H

#if defined(TARGET_PC)
/* PartyBoard host build: no MIPS assembly. Every unit compiled on the host has C for its
   functions (NON_MATCHING), so these expand to nothing. */
#ifndef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME)
#endif
#ifndef INCLUDE_RODATA
#define INCLUDE_RODATA(FOLDER, NAME)
#endif
#elif !defined(SPLAT) && !defined(M2CTX) && !defined(PERMUTER)
#ifndef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME) \
    __asm__( \
        ".section .text\n" \
        "    .set noat\n" \
        "    .set noreorder\n" \
        "    .globl " #NAME ".NON_MATCHING\n" \
        "    .type " #NAME ".NON_MATCHING, @object\n" \
        "    " #NAME ".NON_MATCHING:\n" \
        "    .include \"" FOLDER "/" #NAME ".s\"\n" \
        "    .set reorder\n" \
        "    .set at\n" \
    )
#endif
#ifndef INCLUDE_RODATA
#define INCLUDE_RODATA(FOLDER, NAME) \
    __asm__( \
        ".section .rodata\n" \
        "    .include \"" FOLDER "/" #NAME ".s\"\n" \
        ".section .text" \
    )
#endif
__asm__(".include \"include/labels.inc\"\n");
#else
#ifndef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME)
#endif
#ifndef INCLUDE_RODATA
#define INCLUDE_RODATA(FOLDER, NAME)
#endif
#endif

#endif