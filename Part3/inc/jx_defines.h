#ifndef JX_DEFINES_H
#define JX_DEFINES_H

#include "jx_configs.h"
#include "jx_types.h"

#define _char char
//used for hide some modules
#define _null_statement() do{}while(0)

//min,max
#define _min(a,b) ( ( (a) < (b) ) ? (a) : (b) )
#define _max(a,b) ( ( (a) > (b) ) ? (a) : (b) )

//swap
//if a is b,error
#define _swap(a,b) do{a = a^b; b = a^b; a = a^b;}while(0)
//_T_ is the data type
#define _swapT(a,b,_T_) do{register _T_ __t = a; a = b; b = __t;}while(0)

//left and right shifts,count by bit
#define _rshf(a,n) ( (a) >> (n) )
#define _lshf(a,n) ( (a) << (n) )

//fill n 0s on the right,count by bit
#define _Lclr(a,n) _lshf(_rshf(a,n),n)
//fill n 0s on the left,count by bit
#define _Hclr(a,n) _rshf(_lshf(a,n),n)

//left and right shifts,count by bytes
#define _rshfB(a,n) _rshf(a,(n) * 8)
#define _lshfB(a,n) _lshf(a,(n) * 8)

//fill n bytes of 0s on the right
#define _LclrB(a,n) _lshfB(_rshfB(a,n),n)
//fill n bytes of 0s on the left
#define _HclrB(a,n) _rshfB(_lshfB(a,n),n)

//combine data within 2 memory units
#if 0
_u32 pi32[2] = {0x76543210,0xfedcba98};
_getB(pi32,3,_u32) => 0x76543210 >> (3 * 8) | 0xfedcba98 << ((4 - 3) * 8) = 0xdcba9800 | 0x76 = 0xdcba9876
#endif

//little endian system
#ifdef LITTLE_ENDIAN
    #define _getB(pa,n,_T_) (_rshfB(pa[0],n) | _lshfB(pa[1],sizeof(_T_) - n))
#else
    #define _getB(pa,n,_T_) _null_statement()
#endif

//flush a's higher sizeof(_T_) - n bytes,flush b's lower n bytes,combine them
#define _unionB(a,b,n,_T_) (_HclrB(a,sizeof(_T_) - (n)) | _lshfB(b,n))

//get n bits size
#define _BITS_SIZE(n) (1 << (n))
//get n bits mask
#define _BITS_MASK(n) (_BITS_SIZE(n) - 1)
//the n th bit's mask
#define _BITSET(n) _BITS_SIZE(n)
//get bit th bit's content of d
#define _get_bit(d,bit) ( (d) & _BITSET(bit) )
//set bit th bit's val 1
#define _set_bit(d,bit) do{d |= _BITSET(bit);}while(0)
//set bit th bit's val 0
#define _clr_bit(d,bit) do{d &= (~_BITSET(bit));}while(0)
//check if n th bit is 1
#define _chk_bit(d,bit) ((d) & _BITSET(bit))
#define _chk_bit2(d,bit) ((d) & bit)

#define _Lclr(a,n) ( (a) & ( ~(_BITS_MASK(n) ) ) )
#define _LNclr(a,n) ( (a) & ( _BITS_MASK(n) ) )

//pos n 's mem number
#define _BITPOS(n,bsize) ((n) >> (bsize))
//the offset in 1 unit
#define _BITBIAS(n,bsize) ((n) & _BITS_MASK(bsize))

//some bit ops
#define _get_bits(p,k,bsize) _get_bit((p)[_BITPOS(k,bsize)],_BITBIAS(k,bsize))
#define _set_bits(p,k,bsize) _set_bit((p)[_BITPOS(k,bsize)],_BITBIAS(k,bsize))
#define _clr_bits(p,k,bsize) _clr_bit((p)[_BITPOS(k,bsize)],_BITBIAS(k,bsize))
#define _chk_bits(p,k,bsize) _chk_bit((p)[_BITPOS(k,bsize)],_BITBIAS(k,bsize))

//bits' widths
#define _8bsize 3
#define _16bsize 4
#define _32bsize 5
#define _64bsize 6

#define _get_8_bits(p,k) _get_bits(p,k,_8bsize)
#define _set_8_bits(p,k) _set_bits(p,k,_8bsize)
#define _clr_8_bits(p,k) _clr_bits(p,k,_8bsize)
#define _chk_8_bits(p,k) _chk_bits(p,k,_8bsize)

#define _get_16_bits(p,k) _get_bits(p,k,_16bsize)
#define _set_16_bits(p,k) _set_bits(p,k,_16bsize)
#define _clr_16_bits(p,k) _clr_bits(p,k,_16bsize)
#define _chk_16_bits(p,k) _chk_bits(p,k,_16bsize)

#define _get_32_bits(p,k) _get_bits(p,k,_32bsize)
#define _set_32_bits(p,k) _set_bits(p,k,_32bsize)
#define _clr_32_bits(p,k) _clr_bits(p,k,_32bsize)
#define _chk_32_bits(p,k) _chk_bits(p,k,_32bsize)

#define _get_64_bits(p,k) _get_bits(p,k,_64bsize)
#define _set_64_bits(p,k) _set_bits(p,k,_64bsize)
#define _clr_64_bits(p,k) _clr_bits(p,k,_64bsize)
#define _chk_64_bits(p,k) _chk_bits(p,k,_64bsize)

//check chars
//小写、大写、数字、可显示、仅有空格和tab的空白字符、属于空格但不属于空白字符、十六进制中字母检测
enum{
    ENUM_Lchars = 0,
    ENUM_Uchars,
    ENUM_Nchars,
    ENUM_Pchars,
    ENUM_Bchars,
    ENUM_CBchars,
    ENUM_Hchars,
};

//0x1
#define _LcharMASK _BITSET(ENUM_Lchars)
//0x2
#define _UcharMASK _BITSET(ENUM_Uchars)
#define _NcharMASK _BITSET(ENUM_Nchars)
#define _PcharMASK _BITSET(ENUM_Pchars)
#define _BcharMASK _BITSET(ENUM_Bchars)
#define _CBcharMASK _BITSET(ENUM_CBchars)
#define _HcharMASK _BITSET(ENUM_Hchars)

//并集的屏蔽码
//字母
#define _AcharMASK (_LcharMASK | _UcharMASK)
//空白字符
#define _ScharMASK (_BcharMASK | _CBcharMASK)
//字母和数字
#define _ANcharMASK (_AcharMASK | _NcharMASK)

enum{
    ENUM_TAB_CLR = 0,
    ENUM_TAB_SET
};

extern _u8 CHARS_TAB[256];
extern _u8 UTF8_TAB[256];

#define _islower(c) _chk_bit2(CHARS_TAB[(_u8)(c)],_LcharMASK)
#define _isupper(c) _chk_bit2(CHARS_TAB[(_u8)(c)],_UcharMASK)
#define _isalpha(c) _chk_bit2(CHARS_TAB[(_u8)(c)],_AcharMASK)
#define _isdigit(c) _chk_bit2(CHARS_TAB[(_u8)(c)],_NcharMASK)
#define _isalnum(c) _chk_bit2(CHARS_TAB[(_u8)(c)],_ANcharMASK)
#define _isprint(c) _chk_bit2(CHARS_TAB[(_u8)(c)],_PcharMASK)
#define _isblank(c) _chk_bit2(CHARS_TAB[(_u8)(c)],_BcharMASK)
#define _isspace(c) _chk_bit2(CHARS_TAB[(_u8)(c)],_ScharMASK)
#define _isxdigit(c) _chk_bit2(CHARS_TAB[(_u8)(c)],_HcharMASK)


enum{
    ENUM_UTF8_BYTES = 0,
    ENUM_UTF8_BYTE0 = 3,
    ENUM_UTF8_BYTE1,
    ENUM_UTF8_BYTE2,
    ENUM_UTF8_BYTE3,
    ENUM_UTF8_ASCII = 7,
};

#define UTF8_BYTES_SIZE ENUM_UTF8_BYTE0

_u8 *makevalTAB(_I,_I);

//字符值p的第i个字节
#define _getUTF8_DATA(p,i) *((_u8*)(p) + i)
#define _UTF8VAL(p,i) UTF8_TAB[_getUTF8_DATA(p,i)]
#define _UTF8LEN(p) (_UTF8VAL(p,0) & _BITS_MASK(UTF8_BYTES_SIZE))
#define _UTF8ASCII(p) _chk_bit(_UTF8VAL(p,0),ENUM_UTF8_ASCII)
#define _UTF8NULL(p) ((_UTF8VAL(p,0) == 0xc0) && (_UTF8VAL(p,1) == 0x80))

_I isUTF_8(_u8 *p);

extern const _u32 _CHKUTF8TAB[];

#define _getUTF8MASK(p) _CHKUTF8TAB[_UTF8LEN(p)]
#define _getUTF8_32(p) ((_u32)_UTF8VAL(p,1) |\
_lshf((_u32)_UTF8VAL(p,2),8) |\
_lshf((_u32)_UTF8VAL(p,3),16)\
)

#define _chkUTF8MASK(p,mask) ((_getUTF8_32(p) & mask) == mask)
#define _chkUTF8(p) (_UTF8LEN(p) && _chkUTF8MASK(p,_getUTF8MASK(p)))

#endif