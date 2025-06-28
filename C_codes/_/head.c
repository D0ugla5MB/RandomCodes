#include <stdio.h>
#include "head.h"


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