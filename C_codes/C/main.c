#include <stdio.h>
#include <string.h>

void playWithChars(char str[])
{
    /*
        ARRAY DECAY: when an arr is passed to a func, it decays into a ptr to its 1st elem
            void func1(char str[]) {  Equivalent to char *str  }
            void func2(char *str){ Equivalent to char str[] }
    */

    int len = strlen(str);
    size_t lenA = strlen(str);

    printf("%s\n\n", str);
    printf("%d\n\n", len);
    printf("%zu\n\n", lenA);
}

char *getNum(char *num)
{
    return num;
}

union Number
{
#define MIN_NUM_LEN 8
#define MAX_NUM_LEN 64
    int num_len;
    char *num_str;
} Number;

void doFile(char *fn, char *m)
{
    FILE *file = fopen(fn, m);
    if (!file)
    {
        printf("Not printed %s\n", fn);
        return;
    }

    char cf = ' ';
    while ((cf = fgetc(file)) != EOF)
    {
        printf("%c", cf);
    }

    fclose(file);
    return;
}

int main()
{
    //    doFile("test.txt", "r");
    const char *source = "This is a string that is exactly sixty-four characters long abcdefghij"; // 64 characters

    playWithChars(source);

    return 0;
}