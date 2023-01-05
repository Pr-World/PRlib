#include <types/str.h>
#include <stdio.h>
#include <stdlib.h>

/// @brief the normal string constructor
/// @param args if not present, initialize the string else store the string provided.
#define string(args...) string_construct(cpoly(0, ##args))

// use cpoly to construct string
string string_construct(cpoly_fmt_type fmt, ...) {
    
    cpolyarg_start(args, fmt);

    if ( cpoly_arg_len(fmt) == 0 ) {
        return str_init();
    } else if ( cpoly_arg_len(fmt) == 1 ) {

        if ( cpoly_get_type(fmt) == CTYPE_STRING ) {
            return str_from_char(cpolyarg_get(args, char*));
        }

    }

    cpolyarg_end(args);
}

int str_print(iotype* val) {
    return printf("%s", ((string*)(val)) -> c_str);
}

size_t str_size(string x) {
    return x.size;
}

size_t str_len(string x) {
    return strlen(x.c_str);
}

int str_input(iotype* var) {
    string* str = (string*)var;

    // if previous one is already allocated, free it & proceed
    if ( str -> size ) {
        free(str -> c_str);
    }
    str -> size = 0;
    
    // take input
    char local[STR_MAX_ARR];

    fgets(local, STR_MAX_ARR, stdin);
    local[strlen(local)-1] = '\0'; // clear out the '\n'

    str -> size = strlen(local)+1;
    str -> c_str = (char*) malloc(str -> size);
    if ( str -> c_str == NULL) {
        return -1; // unsuccessfull!
    }

    strncpy(str -> c_str, local, str -> size+1);
    return 1;
}

string str_init() {
    iotype l = {str_print, str_input};
    string x = {l, "", 0};
    return x;
}

string str_from_char(char* x)
{
    string rt = str_init();
    rt.c_str = x;
    return rt;
}

string str_clear(string str) {
    if ( str.size ) {
        free(str.c_str);
    }
    str = str_init();
    return str;
}