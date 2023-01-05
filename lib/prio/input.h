#if !defined(PRINPUT_H_INCL)
#define PRINPUT_H_INCL

#include <vararg/vararg.h>
#include <types/iotype.h>

// scanf wrappers for input
int scan____int(void*);
int scan____uint(void*);
int scan____short(void*);
int scan____ushort(void*);
int scan____long(void*);
int scan____ulong(void*);
int scan____double(void*);
int scan____float(void*);
int scan____string(void*);
int scan____char(void*);

int scan__too_many();
int scan__too_less();
int scan____dummy();
int scan____unknown(void*);

// input on null
#define IN0 scan____dummy

#define input__in(var) (input___in(var))((input___pntr(var)))

// if a string then directly pass variable else get it's address
#define input___pntr(var) _Generic(var,\
    default: (&var), \
    char*: var \
)

// choose scan functions according to the types
#define input___in(var) _Generic((var),\
    default: scan____unknown,\
    short: scan____short,\
    unsigned short: scan____ushort,\
    int: scan____int,\
    unsigned int: scan____uint,\
    long: scan____long,\
    unsigned long: scan____ulong,\
    float: scan____float,\
    double: scan____double,\
    char: scan____char,\
    char *: scan____string \
)

// scan upto 14 arguments!
#define scan__1(w,x,_d...) input__in(x)
#define scan__2(w,x,y,_d...) scan__1(w,x)+scan__1(w,y)
#define scan__3(w,x,y,z,_d...) scan__2(w,x,y)+scan__1(w,z)
#define scan__4(w,x,y,z,a,_d...) scan__3(w,x,y,z)+scan__1(w,a)
#define scan__5(w,x,y,z,a,b,_d...) scan__4(w,x,y,z,a)+scan__1(w,b)
#define scan__6(w,x,y,z,a,b,c,_d...) scan__5(w,x,y,z,a,b)+scan__1(w,c)
#define scan__7(w,x,y,z,a,b,c,d,_d...) scan__6(w,x,y,z,a,b,c)+scan__1(w,d)
#define scan__8(w,x,y,z,a,b,c,d,e,_d...) scan__7(w,x,y,z,a,b,c,d)+scan__1(w,e)
#define scan__9(w,x,y,z,a,b,c,d,e,f,_d...) scan__8(w,x,y,z,a,b,c,d,e)+scan__1(w,f)
#define scan__10(w,x,y,z,a,b,c,d,e,f,g,_d...) scan__9(w,x,y,z,a,b,c,d,e,f)+scan__1(w,g)
#define scan__11(w,x,y,z,a,b,c,d,e,f,g,h,_d...) scan__10(w,x,y,z,a,b,c,d,e,f,g)+scan__1(w,h)
#define scan__12(w,x,y,z,a,b,c,d,e,f,g,h,i,_d...) scan__11(w,x,y,z,a,b,c,d,e,f,g,h)+scan__1(w,i)
#define scan__13(w,x,y,z,a,b,c,d,e,f,g,h,i,j,_d...) scan__12(w,x,y,z,a,b,c,d,e,f,g,h,i)+scan__1(w,j)
#define scan__14(w,x,y,z,a,b,c,d,e,f,g,h,i,j,k,_d...) scan__13(w,x,y,z,a,b,c,d,e,f,g,h,i,j)+scan__1(w,k)

/// @brief input into variables
/// @param variables variables to input to!
#define input(variables...) input_wrp(0, ##variables)

#define input_wrp(_d,var...) \
    vararg_if(0, scan__too_less(), ##var) \
    vararg_if(1, scan__1(0,##var,IN0), ##var) \
    vararg_if(2, scan__2(0,##var,IN0,IN0), ##var) \
    vararg_if(3, scan__3(0,##var,IN0,IN0,IN0), ##var) \
    vararg_if(4, scan__4(0,##var,IN0,IN0,IN0,IN0), ##var) \
    vararg_if(5, scan__5(0,##var,IN0,IN0,IN0,IN0,IN0), ##var) \
    vararg_if(6, scan__6(0,##var,IN0,IN0,IN0,IN0,IN0,IN0), ##var) \
    vararg_if(7, scan__7(0,##var,IN0,IN0,IN0,IN0,IN0,IN0,IN0), ##var) \
    vararg_if(8, scan__8(0,##var,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0), ##var) \
    vararg_if(9, scan__9(0,##var,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0), ##var) \
    vararg_if(10, scan__10(0,##var,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0), ##var) \
    vararg_if(11, scan__11(0,##var,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0), ##var) \
    vararg_if(12, scan__12(0,##var,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0), ##var) \
    vararg_if(13, scan__13(0,##var,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0), ##var) \
    vararg_if(14, scan__14(0,##var,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0,IN0), ##var) \
vararg_else(scan__too_many())


#endif // PRINPUT_H_INCL
