#include "jx_types.h"
#include "jx_delog.h"

#if 0
    init_delog -> Npos_delog -> _jx_delog -> _init_delog 
    -> va_copy_statement -> s_init_delog -> _pos_delog
    -> _jx_delog -> _init_delog -> _initMSG
#endif

_i32 main(_i32 argc,_s argv[]){
    init_delog();
    //printf("%s",__FILE__);
    return 0;
}