/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 2.9  Rewrite the function lower, which converts upper case 
    letters to lower case, with a conditional expression instead of if-else. 

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-22
*/
#include <stdio.h>

int lower2(int c);

int main()
{
    int c = 'U';
    printf("%c --> %c\n", c, lower2(c));

    return 0;
}

int lower2(int c)
{
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}