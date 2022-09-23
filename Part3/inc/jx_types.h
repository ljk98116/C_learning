#ifndef _JX_TYPES_H
#define _JX_TYPES_H

typedef signed char _i8;
typedef unsigned char _u8;
typedef signed short _i16;
typedef unsigned short _u16;
typedef signed int _i32;
typedef signed long long _i64;
typedef unsigned long long _u64;
typedef unsigned int _u32;
typedef unsigned int _I;
typedef char _c;
typedef char *_s;
typedef _u8 *_P;

#define _getva_T_(P,params,_T_) do{P = (_T_)va_arg(params,_T_);} while(0)
#define _getva_S(s,params) _getva_T_(s,params,_s)
#define _getva_I(i,params) _getva_T_(i,params,_I)
#define _getva_P(i,params) _getva_T_(i,params,_P)
#define _getva_double(i,params) _getva_T_(i,params,double)
#define mkstr(symbol) #symbol

#endif