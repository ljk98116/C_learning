#include <string.h>
#include "param.h"

enum{
    #define ENUM_INFO
    #include "paramDef.h"
    _MAX_MODE
};

const char * const MODESTR[_MAX_MODE] = {
    #define MODESTR_INFO
    #include "paramDef.h"
};

typedef int (*pCHKPARAMFUC)(int argc,char *argv[]);

#define FUNCDECLARE_INFO
#include "paramDef.h"

static const pCHKPARAMFUC chkParam[_MAX_MODE] = {
    #define FUNCNAME_INFO
    #include "paramDef.h"
};

enum{
    _ENUM_MIN_PARAM_NUM = 3
};

int g_chkre;
static int s_argc;
static char **s_argv;

static void print_param(void){
    static int s_count = 0;
    if(s_count >= s_argc){
        printf("\n");
        s_count = 0;
        return;
    }
    printf("%s",s_argv[s_count]);
    if(s_argv[s_count][0] == '-'){
        g_chkre = 1;
    }
    s_count++;
    print_param();
}

int chk_param(int argc,char *argv[]){
    int re = -1;
    int i;
    _error(argc < 2,_chk_param_END," param less !only %d\n",argc);
    _error(argv[1][0]!='-',_chk_param_END,"the %s param error ,need '-'\n",argv[1]);

    for(i=0;i<_MAX_MODE;i++){
        if(strcmp(&argv[1][1],MODESTR[i]) == 0){
            chkParam[i](argc-2,argv+2);
            re = 0;
            goto _chk_param_END;
        }
    }
    _error(i >=_MAX_MODE,_chk_param_END," no found this mode %s\n",argv[1]);
_chk_param_END:
    return re;
}