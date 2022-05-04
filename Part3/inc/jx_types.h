typedef signed char _i8;
typedef unsigned char _u8;
typedef signed int _i32;
typedef unsigned int _u32;
typedef unsigned int _I;
typedef char _c;
typedef char *_s;

#define _getva_T_(P,params,_T_) do{P = (_T_)va_arg(params,_T_);} while(0)
#define _getva_S(s,params) _getva_T_(s,params,_s)
#define _getva_I(i,params) _getva_T_(i,params,_I)
