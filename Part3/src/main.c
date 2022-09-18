#include "jx_delog.h"
#include "jx_definesTemp.h"
#include "jx_defines.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//设置对应的字符集合，输出一个字符串，比如小写字母的集合，"a,b,c,d,..."，以'\0'结尾
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
    int x = _isupper('A');
    printf("0x%x %d\n",CHARS_TAB['A'],x);
    return;
}

void create_UTF8_TAB(void)
{                                                                                                                                                                                                                                                  
    _I i;
    _I bytes;
    _u8 *psets;
    for(i=0;i<256;i++)
    {
        UTF8_TAB[i] = 0;
    }
    bytes = 1;
    psets = makevalTAB(0,128);
    
    set8TAB(UTF8_TAB,ENUM_UTF8_ASCII,ENUM_TAB_SET,1,psets);
    set8TAB(UTF8_TAB,ENUM_UTF8_BYTE0,ENUM_TAB_SET,1,psets);
    setval8TAB(UTF8_TAB,ENUM_UTF8_BYTES,3,bytes,1,psets);
    
    psets = makevalTAB(0x80,0xc0 - 0x80);
    
    set8TAB(UTF8_TAB,ENUM_UTF8_BYTE1,ENUM_TAB_SET,0,psets);
    set8TAB(UTF8_TAB,ENUM_UTF8_BYTE2,ENUM_TAB_SET,0,psets);
    set8TAB(UTF8_TAB,ENUM_UTF8_BYTE3,ENUM_TAB_SET,0,psets);
    
    bytes = 2;
    psets = makevalTAB(0xc0,0xe0 - 0xc0);
    set8TAB(UTF8_TAB,ENUM_UTF8_BYTE0,ENUM_TAB_SET,0,psets);
    setval8TAB(UTF8_TAB,ENUM_UTF8_BYTES,3,bytes,0,psets);

    
    bytes = 3;
    psets = makevalTAB(0xe0,0xf0 - 0xe0);
    set8TAB(UTF8_TAB,ENUM_UTF8_BYTE0,ENUM_TAB_SET,0,psets);
    setval8TAB(UTF8_TAB,ENUM_UTF8_BYTES,3,bytes,0,psets);

    
    bytes = 4;
    psets = makevalTAB(0xf0,0xf8 - 0xf0);
    set8TAB(UTF8_TAB,ENUM_UTF8_BYTE0,ENUM_TAB_SET,0,psets);
    setval8TAB(UTF8_TAB,ENUM_UTF8_BYTES,3,bytes,0,psets);

    print8TAB(UTF8_TAB,"UTF8_TAB",16,stdout);
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
    create_UTF8_TAB();
    //printf("%d\n",_chkUTF8("U"));
#endif
    return 0;                                                                                                                                 
}