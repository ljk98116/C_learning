#include "jx_delog.h"
#include "jx_definesTemp.h"
#include "jx_defines.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define setstrset(pstr,chkfunc,zero) do{\
_I __i,__j;\
__j = 0;\
zero = chkfunc(0);\
for(__i = 1;__i < 256;__i++){\
    if(chkfunc(__i))\
    {\
        pstr[__j] = __i;\
        __j++;\
    }\
    pstr[__j] = 0;\
}\
}while(0)

void create_CHARS_TAB(void)
{
    _u8 CHARS_TAB[256];
    _u8 strsets[256];
    _I zero;
    _I i;
    for(i=0;i<256;i++)
    {
        CHARS_TAB[i] = 0;
    }
    setstrset(strsets,islower,zero);
    set8TAB(CHARS_TAB,ENUM_Lchars,ENUM_TAB_SET,zero,(_u8*)strsets);

    setstrset(strsets,isupper,zero);
    set8TAB(CHARS_TAB,ENUM_Uchars,ENUM_TAB_SET,zero,(_u8*)strsets);

    setstrset(strsets,isdigit,zero);
    set8TAB(CHARS_TAB,ENUM_Nchars,ENUM_TAB_SET,zero,(_u8*)strsets);

    setstrset(strsets,isprint,zero);
    set8TAB(CHARS_TAB,ENUM_Pchars,ENUM_TAB_SET,zero,(_u8*)strsets);

    setstrset(strsets,isxdigit,zero);
    set8TAB(CHARS_TAB,ENUM_Hchars,ENUM_TAB_SET,zero,(_u8*)strsets);
    strcpy((_s)strsets," \t");
    zero = 0;

    set8TAB(CHARS_TAB,ENUM_Bchars,ENUM_TAB_SET,zero,(_u8*)strsets);
    strcpy((_s)strsets,"\f\n\r\v");
    zero = 0;

    set8TAB(CHARS_TAB,ENUM_CBchars,ENUM_TAB_SET,zero,(_u8*)strsets);
    print8TAB(CHARS_TAB,"CHARS_TAB",16,stdout);
    return;
}
#if 0
    init_delog -> Npos_delog -> _jx_delog -> _init_delog 
    -> va_copy_statement -> s_init_delog -> _pos_delog
    -> _jx_delog -> _init_delog -> _initMSG -> getPosInfo 
    -> va_copy_statement
#endif
 
//#define SNPRINTF_TEST 
#define CREATE_CHARSTAB
#define BUF_SIZE 40

_i32 main(_i32 argc,_s argv[]){

#ifdef FWRITE_TEST
    init_delog();
    FILE *f = 0;
    _OPENFILE(f,"test","wb",_main_END);
    fwrite("test info\n",1,strlen("test info\n"),f);
_main_END:
    _CLOSEFILE(f);
    return 0;
#endif

#ifdef SNPRINTF_TEST
    _c buf[BUF_SIZE];
    snprintf(buf,BUF_SIZE,"%d:%s",argc,argv[0]);
    printf("%s\n",buf);
#endif

#ifdef CREATE_CHARSTAB
    create_CHARS_TAB();
#endif
    return 0;                                                                                                                                 
}