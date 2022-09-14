#ifndef JX_DEFINESTEMP_H
#define JX_DEFINESTEMP_H

#include "jx_types.h"
#define A _u8

#ifndef _BSIZE
    #define _BSIZE 3
#endif

#if _BSIZE == 3
#define __T__ _u8
#elif _BSIZE == 4
#define __T__ _u16
#elif _BSIZE == 5
#define __T__ _u32
#elif _BSIZE == 6
#define __T__ _u64
#else
#error _BSIZE only defined 3(_u8) 4(_u16) 5(_u32) 6(_u64)  !
#endif

#ifdef __setTAB

/*
**@summary 对不同集合进行设置，表示该字符属于哪一个集合，每个集合由8位中的一位表示是否属于
**@param ptab 要设置的表
**@param bit 当前设置的位
**@param set 设置还是清除
**@param _zero 是否包含字符'\0'
**@param psets 检测集合中非'\0'元素组成的字符串
*/
_I __setTAB(__T__ *ptab,_I bit,_I set,_I _zero,_u8 *psets)
{
    _I re = 0;
    if(bit >= _BITS_SIZE(_BSIZE))
    {
        goto __func_END;
    }
    if(set == ENUM_TAB_SET)
    {
        while(psets[0])
        {
            _set_bit(ptab[psets[0]],bit);
            psets++;
        }
        if(_zero)
        {
            _set_bit(ptab[0],bit);
        }
    }
    else
    {
        while(psets[0])
        {
            _clr_bit(ptab[psets[0]],bit);
            psets++;
        }
        if(_zero)
        {
            _clr_bit(ptab[0],bit);
        }
    }
    re = 0;
__func_END:
    return re;
}
#undef __setTAB
#endif

#ifdef __printTAB
#include <stdio.h>
#define __NAME(exp) mkstr(exp)
void __printTAB( __T__ *ptab,_s name,_I width,FILE *f)
{
    _I i,j;
    fprintf(f,"const %s[256] = {\n",name);
    width = _max(width,8);
    i = j = 0;
    while(i < 255)
    {
        fprintf(f," 0x%llx,",(_u64)ptab[i]);
        i++;
        j++;
        if(j == width)
        {
            j = 0;
            fprintf(f,"\n");
        }
    }
    fprintf(f," 0x%llx};\n",(_u64)ptab[i]);
    return;
}
#undef __NAME
#undef __printTAB
#endif

#ifdef __setvalTAB
_I __setvalTAB(__T__ *ptab,_I bit,_I width,_I val,_I _zero,_u8 *psets)
{
    _I re = 0;
    if(bit + width >= _BITS_SIZE(_BSIZE))
    {
        goto __func_END;
    }
    val &= _BITS_MASK(width);
    val = _lshf(val,bit);
    while(psets[0])
    {
        ptab[psets[0]] |= val;
        psets++;
    }
    if(_zero)
    {
        ptab[0] |= val;
    }
    re = 0;
__func_END:
    return re;
}
#undef __setvalTAB
#endif

#undef __T__
#undef _BSIZE

#endif