/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 1.2. Experiment to find out what happens when printf's argument
    string contains '\c', which is not defined as escape sequence.

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-3-28
*/
#include <stdio.h>

int main()
{
    printf("an escape sequence which is not defined like \'\\c\' is printed as:\n\c\n");

    return 0;

    /*
        Answer: just print the char 'c'.
    */
}