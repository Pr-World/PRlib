#include <prio/input.h>
#include <stdio.h>

int scan____int(void* x) { return scanf(" %d", (int*) x); }
int scan____uint(void* x) { return scanf(" %u", (unsigned*) x); }
int scan____short(void* x) { return scanf(" %hi", (short*) x); }
int scan____ushort(void* x) { scanf(" %hu", (unsigned short*) x); }
int scan____long(void* x) { return scanf(" %li", (long*) x); }
int scan____ulong(void* x) { return scanf(" %lu", (unsigned long*) x); }
int scan____double(void* x) { return scanf(" %lf", (double*) x); }
int scan____float(void* x) { return scanf(" %f", (float*) x); }
int scan____string(void* x) { return scanf(" %[^\n]s", (char *) x); }
int scan____char(void* x) { return scanf(" %c", (char*) x); }

// attempt to input using iotype
int scan____unknown(void* val) {
    return ((iotype*)val) -> get((iotype*)val);
}

int scan__too_many() {
    printf("\n`input()` got too many arguments, maximum is 14");
    return -1; // error
}

int scan____dummy() {
    // this should never be executed unless explicitly called
    printf("\n`input()` internal error occurred, this shouldn't happen!");
    return -1;
}

int scan__too_less() {
    printf("\n`input()` got less than 1 argument.");
    return -1;
}