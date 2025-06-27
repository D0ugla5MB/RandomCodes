#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    if (x < 10)
        return true;
    
    int cpx = x;
    int divisor = 1;
    while (cpx >= 10) {
        cpx /= 10;
        divisor *= 10;
    }
    cpx = x;
    while (cpx > 0) {
        int first_digit = cpx / divisor;
        int last_digit = cpx % 10;
        
        if (first_digit != last_digit)
            return false;
        
        cpx = (cpx % divisor) / 10;
        divisor /= 100;  
    }
    
    return true;
}

int main()
{
    int test = 12221;
    if (isPalindrome(test))
        printf("%d is a palindrome\n", test);
    else
        printf("%d is not a palindrome\n", test);
    
    test = 12345;
    if (isPalindrome(test))
        printf("%d is a palindrome\n", test);
    else
        printf("%d is not a palindrome\n", test);
    
    return 0;
}