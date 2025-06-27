#include <stdio.h>

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
    doFile("test.txt", "r");
    return 0;
}