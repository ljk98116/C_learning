#include "jx_defines.h"

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