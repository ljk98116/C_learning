#include "jx_types.h"
#include "jx_delog.h"

#include <stdio.h>
#include <string.h>

#if 0
    init_delog -> Npos_delog -> _jx_delog -> _init_delog 
    -> va_copy_statement -> s_init_delog -> _pos_delog
    -> _jx_delog -> _init_delog -> _initMSG -> getPosInfo 
    -> va_copy_statement
#endif

_i32 main(_i32 argc,_s argv[]){
    init_delog();
    FILE *f = 0;
    _OPENFILE(f,"test","wb",_main_END);
    fwrite("test info\n",1,strlen("test info\n"),f);
_main_END:
    _CLOSEFILE(f);
    return 0;
}