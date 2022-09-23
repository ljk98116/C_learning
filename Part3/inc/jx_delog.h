#ifndef _JX_DELOG_H
#define _JX_DELOG_H

    #include "jx_types.h"
    #include "jx_defines.h"
    #include <errno.h>
    #include <string.h>

    #define _POS_INFOBITS (_I)1
    #define _NPOS_INFOBITS (~_POS_INFOBITS)
    #define _SHIFT_INFOBITS 1
    enum{
        _INIT_INFO_DELOG = 0,
        _LOG_INFO_DELOG,
        _DBG_INFO_DELOG,
        _MAX_INFO_DELOG,
    };

    #define init_delog(dbgname,logname) do{_Npos_delog(_INIT_INFO_DELOG,dbgname,logname);} while (0)
    #define _log_info(...) _Npos_delog(_LOG_INFO_DELOG,__VA_ARGS__)
    #define _reg() _log_info("[%s] run!",__func__)
    #define _debug_info(expstr,m,...) _pos_delog(_DBG_INFO_DELOG,m,expstr,__VA_ARGS__)

    #define _sa(exp,len) _debug_info(mkstr(exp),"a",exp,len)
    #define _sx(exp) _debug_info(mkstr(exp),"x",(_u32)exp)
    #define _sI(exp) _debug_info(mkstr(exp),"I",exp)
    #define _sf(exp) _debug_info(mkstr(exp),"f",(double)exp)
    #define _ss(exp) _debug_info(mkstr(exp),"s",(_s)exp)
    #define _sp(exp) _debug_info(mkstr(exp),"p",&exp)
    #define _sc(exp) _debug_info(mkstr(exp),"c",(_i32)exp)
    #define _si(exp) _debug_info(mkstr(exp),"d",(_i32)exp)
    #define _pos() _debug_info("","n","")

    #define _error(exp,escape_label,...) do{if(exp){_debug_info(mkstr(exp),"e",__VA_ARGS__);goto escape_label;}}while(0)
    #define _ERROR(exp,escape_label) _error(exp,escape_label,"system op error (%d):%s",errno,strerror(errno))
    #define _bug(exp) do{if(exp){_debug_info(mkstr(exp),"e","found bug!");exit(0);}}while(0)
    //with position msg
    #define _pos_delog(type,...) _jx_delog((type << 1) | _POS_INFOBITS,__FILE__,__LINE__,__FUNCTION__,__VA_ARGS__)
    //without position msg
    #define _Npos_delog(type,...) _jx_delog((type << 1) & _NPOS_INFOBITS,__VA_ARGS__)

    void _jx_delog(_I type,...);

    //FILE *fopen(const char * filename,const char * mode)
    //fopen is not zero <=> open file success
    #define _OPENFILE(f,name,mode,_label_END) do{\
        if((f = fopen(name,mode)) == 0){\
            goto _label_END;\
        }\
    } while(0)

    //int fclose(FILE *stream)
    #define _CLOSEFILE(f) do{\
        if(f) {fclose(f); f = 0;}\
    } while(0)

#endif