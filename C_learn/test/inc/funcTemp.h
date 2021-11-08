#ifdef _STATIC_PREFIX
    #undef _STATIC_PREFIX
#endif

#ifndef _STATIC_FUNC
    #define _STATIC_PREFIX
#else
    #define _STATIC_PREFIX static
#endif

#ifdef __SUB_FUNC
    _STATIC_PREFIX __T__ __SUB_FUNC(__T__ a,__T__ b){
        return a-b;
    }
#undef __SUB_FUNC
#endif

#ifdef __ADD_FUNC
    _STATIC_PREFIX __T__ __ADD_FUNC(__T__ a,__T__ b){
        return a+b;
    }
#undef __ADD_FUNC
#endif

#undef _STATIC_PREFIX

#ifdef _STATIC_FUNC
    #undef _STATIC_FUNC
#endif

