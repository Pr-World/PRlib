#if !defined(IOTYPE_H_INCL)
#define IOTYPE_H_INCL

#include <stdbool.h>
#include <stdlib.h>

typedef struct iotype
{
    int (*put)(struct iotype*);
    int (*get)(struct iotype*);
} iotype;

#endif // IOTYPE_H_INCL