#if !defined(PROUTPUT_H_INCL)
#define PROUTPUT_H_INCL

#include <vararg/vararg.h>
#include <stdio.h>
#include <types/iotype.h>

#define print__sep printf(" ")

// printf wrappers for print
int print____int(int);
int print____uint(unsigned int);
int print____short(short);
int print____ushort(unsigned short);
int print____long(long);
int print____ulong(unsigned long);
int print____double(double);
int print____float(float);
int print____string(const char *);
int print____char(char);

int print____unknown(void*);

// print function macros
#define print____wn(n, toPrint) printwrap(toPrint)(printval(toPrint)) + ((n==1)?(printf("\n")):(0))

#define printwrap(x) _Generic((x),\
    default: print____unknown,\
    short: print____short,\
    unsigned short: print____ushort,\
    int: print____int,\
    unsigned int: print____uint,\
    long: print____long,\
    unsigned long: print____ulong,\
    float: print____float,\
    double: print____double,\
    char: print____char,\
    char *: print____string,\
    const char *: print____string \
)

#define printval(x) _Generic((x), \
    default: &printadr(x),\
    short: x,\
    unsigned short: x,\
    int: x,\
    unsigned int: x,\
    long: x,\
    unsigned long: x,\
    float: x,\
    double: x,\
    char: x,\
    char *: x,\
    const char *: x \
)

#define printadr(x) _Generic((x),\
    default: x,\
    short: print____unknown,\
    unsigned short: print____unknown,\
    int: print____unknown,\
    unsigned int: print____unknown,\
    long: print____unknown,\
    unsigned long: print____unknown,\
    float: print____unknown,\
    double: print____unknown,\
    char: print____unknown,\
    char *: print____unknown,\
    const char *: print____unknown \
)

// #define print____wn[n]
//(newline(n), a, b, c ...i, p, dummy(an)...)
// if v: print____wn[n-1](a,b,c,...,h) + print__sep + print____wn(n,p) else 0

#define print____wn1(n,p,an...) print____wn(n,p)
#define print____wn2(n,a,p,an...) print____wn(0,a) + print__sep + print____wn(n,p)
#define print____wn3(n,a,b,p,an...) print____wn2(0,a,b) + print__sep + print____wn(n,p)
#define print____wn4(n,a,b,c,p,an...) print____wn3(0,a,b,c) + print__sep + print____wn(n,p)
#define print____wn5(n,a,b,c,d,p,an...) print____wn4(0,a,b,c,d) + print__sep + print____wn(n,p)
#define print____wn6(n,a,b,c,d,e,p,an...) print____wn5(0,a,b,c,d,e) + print__sep + print____wn(n,p)
#define print____wn7(n,a,b,c,d,e,f,p,an...) print____wn6(0,a,b,c,d,e,f) + print__sep + print____wn(n,p)
#define print____wn8(n,a,b,c,d,e,f,g,p,an...) print____wn7(0,a,b,c,d,e,f,g) + print__sep + print____wn(n,p)
#define print____wn9(n,a,b,c,d,e,f,g,h,p,an...) print____wn8(0,a,b,c,d,e,f,g,h) + print__sep + print____wn(n,p)
#define print____wn10(n,a,b,c,d,e,f,g,h,i,p,an...) print____wn9(0,a,b,c,d,e,f,g,h,i)+ print__sep + print____wn(n,p)

/// @brief Prints given argument without newline
/// @param args Arguments to print
#define print_wn(args...) print____internal_wn(0, ## args);

/// @brief Prints given arguments
/// @param args the arguments to print
#define print(args...) print____internal_wn(1, ## args);

#define print____internal_wn(a, args...)                                \
    vararg_if(0, print____wn1(a,""), ##args)                            \
    vararg_if(1, print____wn1(a, ##args, 0), ##args)                    \
    vararg_if(2, print____wn2(a, ##args, 0,0), ##args)                  \
    vararg_if(3, print____wn3(a, ##args, 0,0,0), ##args)                \
    vararg_if(4, print____wn4(a, ##args, 0,0,0,0), ##args)              \
    vararg_if(5, print____wn5(a, ##args, 0,0,0,0,0), ##args)            \
    vararg_if(6, print____wn6(a, ##args, 0,0,0,0,0,0), ##args)          \
    vararg_if(7, print____wn7(a, ##args, 0,0,0,0,0,0,0), ##args)        \
    vararg_if(8, print____wn8(a, ##args, 0,0,0,0,0,0,0,0), ##args)      \
    vararg_if(9, print____wn9(a, ##args, 0,0,0,0,0,0,0,0,0), ##args)    \
    vararg_if(10, print____wn10(a, ##args, 0,0,0,0,0,0,0,0,0,0), ##args)  \
vararg_else( printf("`print()` doesn't support more than 10 arguments.\n") )

#endif // PROUTPUT_H_INCL
