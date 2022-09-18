#include "jx_string.h"
#include "jx_defines.h"

_I strxcpy(_s dst,_s src,_I n)
{
    _I i=0;
    if(n == 0)
    {
        goto _strxcpy_END;
    }
    n--;
    while((i < n) && src[i])
    {
        dst[i] = src[i++];
    }
    dst[i] = 0;
_strxcpy_END:
    return i;
}

_I strxcat(_s dst,_s src,_I n)
{
    _I i=0;
    _I j;
    if(n == 0)
    {
        goto _strxcat_END;
    }
    n--;
    while(dst[i] && (i < n))
    {
        i++;
    }
    j = 0;
    while((i < n) && src[j])
    {
        dst[i++] = src[j++];
    }
    dst[i] = 0;
_strxcat_END:
    return i;
}

_I strUTF8len(_s s,_I *pnum,_I n)
{
    _I i=0;
    _I l;
    _I num = 0;
    _I mask;
    if(n == 0)
    {
        goto _strUTF8len_END;
    }
    n--;
    while((i < n) && (s[0]))
    {
        l = _UTF8LEN(s);
        if(l == 0)
        {
            goto _strUTF8len_END;
        }
        mask = _CHKUTF8TAB[l];
        if(_chkUTF8MASK(s,mask) == 0)
        {
            goto _strUTF8len_END;
        }
        i+=l;
        //空字符不计入字符数量，但加入总长度中
        if(_UTF8NULL(s))
        {
            goto _strUTF8len_END;
        }
        num++;
        s+=l;
    }
_strUTF8len_END:
    if(pnum)
    {
        *pnum = num;
    }
    return i;
}

_u64 *makeCharSetsTAB(_s s,_I zero,_u64 *ptab)
{
    static _u64 tab[4];
    _u64 *pre;
    _I i;
    if(ptab == 0)
    {
        pre = tab;
    }
    else
    {
        pre = ptab;
    }
    for(i=0;i<4;i++)
    {
        pre[i] = 0;
    }
    if(zero)
    {
        _set_64_bits(pre,0);
    }
    i = 0;
    while(s[i])
    {
        _set_64_bits(pre,s[i]);
        i++;
    }
    return pre;
}

_I strxspn(const _u8 *s,_I n,_u64 *ptab)
{
    _I re = 0;
    while(re < n)
    {
        if(_chk_64_bits(ptab,s[re]) == 0)
        {
            goto _strxspn_END;
        }
        re++;
    }
_strxspn_END:
    return re;
}

_I strxcspn(const _u8 *s,_I n,_u64 *ptab)
{
    _I re = 0;
    while(re < n)
    {
        if(_chk_64_bits(ptab,s[re]) == 1)
        {
            goto _strxcspn_END;
        }
        re++;
    }
_strxcspn_END:
    return re;
}

_u8 *strxpbrk(const _u8 *s,_I n,_u64 *ptab)
{
    _I re = 0;
    while(re < n)
    {
        if(_chk_64_bits(ptab,s[re]) == 1)
        {
            goto _strxpbrk_END;
        }
        re++;
    }
_strxpbrk_END:
    return s + re;
}