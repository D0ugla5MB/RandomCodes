#include <stdio.h>
#include "head.h"

void unsafe_macro_type(){
    // https://stackoverflow.com/questions/15575485/function-like-macros-in-c
    #define Sum(a,b) a+b

    int a = Sum(1,1);
    int b = Sum(&a, a);
    char c = '0';
    int d = Sum(c,0);
    printf(
        "#define Max(a,b)  ((a)>(b)) ? (a):(b))\n\n"
        "Anything can be passed through the duo param:\n"
        "Max(1,2)\tMax(a,0)\tMax(&some_var,**some_ptr)\n\nEx.:\n"
        "\tSum(%d , %d) will do: '[...]initialization of 'int' from 'int *' makes integer from pointer[...]'\n"
        "\tSum(%d , 0)'\n"
        ,
        a, b, d);

    return;
}

void array_decay(char str[]){
    //const char c = "PLAYING WITH ARRAY DECAY HERE!";
    // error char arr[] = *str || str;
    char arr = *str;
    char *ptr = str;

    printf("%s\n-------------------------\n", str);
    printf("%c\n", arr);
    printf("%s\n", ptr);

    return; // without some return: '[...] conflicting types'
}