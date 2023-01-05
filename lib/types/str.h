#if !defined(STR_H_INCL)
#define STR_H_INCL

#include <string.h>
#include <types/iotype.h>
#include <cpoly/cpoly.h>

#define STR_MAX_ARR 1000

typedef struct string{
    iotype io; // for input / output using prio
    char* c_str; // actual string
    size_t size; // allocated size, 0 if just pointing
} string;

/// @brief supporter function for dynamic type string construct
string string_construct(cpoly_fmt_type fmt, ...);

/// @brief the normal string constructor
/// @param args if not present, initialize the string else store the string provided.
#define string(args...) string_construct(cpoly(0, ##args))

/// @brief function to create string from char*
/// @param  str the char* to create string from
/// @return string with it's content as str
string str_from_char(char*);

/// @brief function to initialize string
/// @return initialized string
string str_init();

/// @brief Clear the string, free() and ...
/// @param str the string to clear
/// @return the cleared string
string str_clear(string str);

size_t str_len(string x);

/// @brief Size allocated by string
/// @param x the string to get size from
/// @return allocated size in bytes
size_t str_size(string x);

#endif // STR_H_INCL