/* COMPILE COMMAND
    gcc main.c head.c -o _run
*/
#include "head.h"

int main(){
    char str[] = {'P', 'L', 'A', 'Y', 'I', 'N', 'G', ' ', 'W', 'I', 'T', 'H', ' ', 'A', 'R', 'R', 'A', 'Y', ' ', 'D', 'E', 'C', 'A', 'Y', ' ', 'H', 'E', 'R', 'E', '!', '\0'};
    array_decay(str);
    return 0;
}