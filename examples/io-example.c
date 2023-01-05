#include <prio/prio.h>

int main()
{
    int i;
    float f;
    char str[50];

    print("--- I/O example using PRlib ---"); // print adds '\n' in the end.

    print_wn("\nInput an integer : "); // print_without_newline ie. print_wn
    input(i); // input into `i`.

    print("Square of", i, "is", i*i); // display the square

    print_wn("\nNow enter a float : ");
    input(f); // input into `f`.

    
}