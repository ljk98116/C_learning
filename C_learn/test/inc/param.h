#ifndef _PARAM_H
#define _PARAM_H
#include <stdio.h>

#define MIN_PARAM_NUM 3

#define __info(fmt,...) do{\
    printf("[%s]<%s>(%d):",__FILE__,__func__,__LINE__);\
    printf(fmt,__VA_ARGS__);\
}while(0)\

#define mkstr(symbol) #symbol

#define _error(exp,escape_label,fmt,...) do{\
    if(exp){\
        __info("*** error occured *** | %s",mkstr(exp));\
        printf(fmt,__VA_ARGS__);\
        goto escape_label;\
    }\
}while(0)\

#define _pos() __info("\n")

extern int g_chkre;
int chk_param(int argc,char *argv[]);

#endif