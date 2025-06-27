#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int _rng(int *min, int *max)
{
    if (*max < *min)
    {
        return *max + rand() % (*min - *max + 1);
    }
    if (*min == *max)
    {
        return *min;
    }

    return *min + rand() % (*max - *min + 1);
}

int (*rng)(int *min, int *max) = &_rng;