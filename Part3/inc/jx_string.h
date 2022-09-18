#ifndef _JX_STRING_H
#define _JX_STRING_H

#include "jx_types.h"

_I strxcpy(_s dst,_s src,_I n);
_I strxcat(_s dst,_s src,_I n);
_I strUTF8len(_s s,_I *pnum,_I n);

_I strxspn(const _u8 *s,_I n,_u64 *ptab);
_I strxcspn(const _u8 *s,_I n,_u64 *ptab);
_u8 *strxpbrk(const _u8 *s,_I n,_u64 *ptab);

#endif