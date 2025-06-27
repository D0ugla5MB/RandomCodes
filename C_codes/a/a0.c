#include <stdio.h>
#include <stdlib.h>

#define VAL_A 2
#define VAL_B VAL_A * 10
#define do() VAL_A *VAL_B
#define VAL_C \
    do        \
    () * do()

int main()
{
    /* #undef VAL_A
    #define VAL_A 5 // this works though can cause issues
     */
    printf("%d\n", VAL_C);
    printf("%d\n", VAL_A);
    return 0;
}