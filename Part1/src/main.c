#include <string.h>
#include "param.h"
#include "jx_types.h"
#include <setjmp.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int g_chk_paramA(int argc,char *argv[]){
    printf("is mode A! first param is %s\n",argv[0]);
    return 0;
}

int g_chk_paramB(int argc,char *argv[]){
    printf("is mode B! first param is %s\n",argv[0]);
    return 0;
}

int g_chk_paramC(int argc,char *argv[]){
    printf("is mode C! first param is %s\n",argv[0]);
    return 0;
}


int main(int argc,char *argv[]){
    # if 0
    chk_param(argc,argv);
    _main_END:
        return 0;
    #endif
    # if 1
    g_chk_paramA(argc,argv);
    #endif
}