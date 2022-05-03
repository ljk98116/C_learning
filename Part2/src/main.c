#include <assert.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
    setjmp returns 0 by default.
    longjmp changes setjmp's return value(jmp),and jump to setjmp,
    then setjmp returns new jmp value

    In this example,if x1 == x2,
    setjmp returns 0,jmp = 0 ->
    b(x1,x2)-> a(x1,x2) -> longjmp(jmp,2),jmp=2 ->
    setjmp returns 2,jmp = 2 ->
    printf("error")
#endif

static jmp_buf jmp;

float a(float i,float j){
    if(j == 0){
        longjmp(jmp,2);
    }
    return i / j;
}

float b(float x1,float x2){
    return a(x1 + x2, x1 - x2);
}

int main(int argc,char *argv[]){
    float x1,x2;
    assert(argc > 2);
    x1 = atof(argv[1]);
    x2 = atof(argv[2]);
    if(setjmp(jmp) == 0){
        printf("(%f + %f) / (%f - %f) = %f\n",x1,x2,x1,x2,b(x1,x2));
    }
    else{
        printf("error\n");
    }
    return 0;
}