#ifndef _JX_DELOG_H
#define _JX_DELOG_H

    #include "jx_types.h"

    #define _POS_INFOBITS (_I)1
    #define _NPOS_INFOBITS (~_POS_INFOBITS)

    enum{
        _INIT_INFO_DELOG = 0,
        _MAX_INFO_DELOG,
    };

    #define init_delog() do{_Npos_delog(_INIT_INFO_DELOG);} while (0)
    //with position msg
    #define _pos_delog(type,...) _jx_delog((type) | _POS_INFOBITS,__FILE__,__LINE__,__FUNCTION__,__VA_ARGS__)
    //without position msg
    #define _Npos_delog(type,...) _jx_delog((type) & _NPOS_INFOBITS,##__VA_ARGS__)

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