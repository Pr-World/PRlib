#if !defined(LIST_H_INCL)
#define LIST_H_INCL

#include <types/libtype.h>
#include <types/str.h>

union list_u {
    int _int;
    unsigned int _uint;
    long _long;
    unsigned long _ulong;
    short _short;
    unsigned short _ushort;
    char _char;
    char* _str;
    string _string;
    void* _other;
};

typedef struct list {
    libtype val;
    union list_u data;
    unsigned int type;
    
} list;

#endif // LIST_H_INCL
