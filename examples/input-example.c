#include <prio/prio.h>

int main()
{
    int ival;
    float fval;
    double dval;
    char cval;
    char str[50];

    // notice that in either print or input, you don't need to explicitly define the type
    // as of scanf(), you need to provide the format specifier

    // input can support 14 variables at once but to keep the example simple
    // one at a time is used!

    print_wn("Enter integer: ");
    input(ival); // input into `ival`
    print("You entered :", ival); // print output

    print(); // to keep spacing

    print_wn("Enter float: ");
    input(fval); // input into `fval`
    print("You entered :", fval); // print output

    print(); // to keep spacing

    print_wn("Enter double: ");
    input(dval); // input into `dval`
    print("You entered :", dval); // print output

    print(); // to keep spacing
    
    print_wn("Enter a character: ");
    input(cval); // input into `cval`
    print("You entered :", cval); // print output

    print(); // to keep spacing

    print_wn("Enter string: ");
    input(str); // input into `str`
    print("You entered :", str); // print output

    print(); // to keep spacing
}