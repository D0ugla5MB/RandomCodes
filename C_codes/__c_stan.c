#include <stdio.h>

int main()
{
    printf("The C standard version used by this compiler is: ");

#if defined(__STDC_VERSION__)
#if __STDC_VERSION__ >= 202311L
    printf("C23 (ISO/IEC 9899:2024)\n");
#elif __STDC_VERSION__ >= 201710L
    printf("C17 (ISO/IEC 9899:2018)\n");
#elif __STDC_VERSION__ >= 201112L
    printf("C11 (ISO/IEC 9899:2011)\n");
#elif __STDC_VERSION__ >= 199901L
    printf("C99 (ISO/IEC 9899:1999)\n");
#else
    printf("Older C standard with __STDC_VERSION__ defined (e.g., C95)\n");
#endif
#elif defined(__STDC__)
    printf("C89/C90 (ANSI C or ISO C)\n");
#else
    printf("Pre-standard C (e.g., K&R C) or a non-compliant compiler\n");
#endif

    return 0;
}