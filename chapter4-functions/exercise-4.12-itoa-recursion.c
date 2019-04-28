/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 4.3   Adapt the ideas of printd to write a recursive version of itoa; 
    that is, convert an integer into a string by calling a recursive routine

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-28
*/
#include <stdio.h>

void printd(int n);

int main()
{
    int a = 12345;

    printd(a);

    return 0;
}

void printd(int n)
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10) {
        printd(n / 10);
    }
    putchar(n % 10 + '0');
}