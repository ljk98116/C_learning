#include "jx_defines.h"

//letter table
_u8 CHARS_TAB[256];
_u8 UTF8_TAB[256];

#define _BSIZE 3
#define  __setTAB set8TAB 
#define  __printTAB print8TAB
#define __setvalTAB setval8TAB 
#include "jx_definesTemp.h"

#define _BSIZE 4
#define  __setTAB set16TAB 
#define  __printTAB print16TAB
#define __setvalTAB setval16TAB
#include "jx_definesTemp.h"

#define _BSIZE 5
#define  __setTAB set32TAB 
#define  __printTAB print32TAB
#define __setvalTAB setval32TAB
#include "jx_definesTemp.h"

#define _BSIZE 6
#define  __setTAB set64TAB 
#define  __printTAB print64TAB 
#define __setvalTAB setval64TAB
#include "jx_definesTemp.h"

_u8 *makevalTAB(_I f,_I l)
{
    static _u8 tab[256];
    _u8 *pre = tab;
    _I i;
    if(l == 0)
    {
        tab[0] = 0;
        goto _makevalTAB_END;
    }
    l = _min(l,256);
    if(f == 0)
    {
        f++;l--;
    }
    tab[l] = 0;
    i = 0;
    while(i < l)
    {
        tab[i] = f++;i++;
    }
_makevalTAB_END:
    return pre;
}

//判断是否为UTF8
_I isUTF_8(_u8 *p)
{
    _I re = 0;
    _I i;
    _I len;
    //长度为0字节，不是UTF8
    if((len = _UTF8LEN(p)) == 0)
    {
        goto _isUTF8_END;
    }
    for(i=1;i < len;i++)
    {
        //判断后续字节2，3，4是否满足条件
        if(_chk_bit(_UTF8VAL(p,i),ENUM_UTF8_BYTE1 + i) == 0)
        {
            goto _isUTF8_END;
        }
    }
    re = 1;
_isUTF8_END:
    return re;
}

#define BYTESNULL 0
#define BYTES2MASK _BITSET(ENUM_UTF8_BYTE1)
#define BYTES3MASK (_BITSET(ENUM_UTF8_BYTE2 + 8) | BYTES2MASK)
#define BYTES4MASK (_BITSET(ENUM_UTF8_BYTE3 + 16) | BYTES3MASK)

const _u32 _CHKUTF8TAB[5] = 
{
    BYTESNULL,BYTESNULL,BYTES2MASK,BYTES3MASK,BYTES4MASK,
};
