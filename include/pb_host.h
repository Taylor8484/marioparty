#ifndef PB_HOST_H
#define PB_HOST_H

/*
 * PartyBoard host-port types (https://github.com/Taylor8484/partyboard4, games/mp1).
 *
 * Every type here expands to the exact original N64 type when TARGET_PC is undefined, so the
 * matching build is unchanged by construction. On the host (TARGET_PC, LP64/LLP64) they widen
 * integers that the game uses to hold addresses.
 *
 *   PB_PTR32   s32 on N64, intptr_t on the host: a signed 32-bit integer that holds a pointer.
 *   PB_UPTR32  u32 on N64, uintptr_t on the host: the unsigned counterpart.
 *   PB_ROM_ADDR(a)  host only: a ROM offset that the N64 links as a symbol (see below).
 *   PB_N64_ADDR(T, a)  an N64 address kept as data that the host never dereferences (the
 *              overlay segment table): ((T)(a)) on N64, through uintptr_t on the host.
 *   PB_HOSTCAST(T, x)  ((T)(x)) on the host, (x) on N64: a conversion the N64 code performs
 *              implicitly (an int passed where a pointer is expected, or back), made explicit
 *              for the host only.
 */

#include "PR/ultratypes.h"

#ifdef TARGET_PC
/* The C library the game calls without prototypes on the N64 (sprintf, bcopy, strlen, sinf...).
 * Included here, ahead of PR/os.h, which #undefs the CRT's errno macro for its struct fields. */
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* libultra's libc (os_libc.h); the host build provides them where the C library does not. */
void bcopy(const void *src, void *dst, size_t len);
void bzero(void *dst, size_t len);
int bcmp(const void *a, const void *b, size_t len);
typedef intptr_t PB_PTR32;
typedef uintptr_t PB_UPTR32;
#if defined(_MSC_VER) && !defined(__clang__)
/* MSVC has no GNU attributes; the decomp uses aligned(4) on GW_PLAYER only, which x86-64 does
 * not need for correctness. */
#define __attribute__(x)
#endif
#define PB_HOSTCAST(T, x) ((T)(x))
/* A ROM offset the N64 links as a symbol address (an Addr label in undefined_syms.txt or
   ld_addrs.h): an lvalue of type Addr at that numeric address, so &sym and its decay give the
   offset, as on the N64. Never dereferenced: ROM reads go through PI DMA. */
#define PB_ROM_ADDR(a) (*(u8 (*)[])(uintptr_t)(a))
#define PB_N64_ADDR(T, a) ((T)(uintptr_t)(a))
#else
typedef s32 PB_PTR32;
typedef u32 PB_UPTR32;
#define PB_HOSTCAST(T, x) (x)
#define PB_N64_ADDR(T, a) ((T)(a))
#endif

#endif /* PB_HOST_H */
