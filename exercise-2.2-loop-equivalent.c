/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 2.2 Write a program to determine the ranges of char, short, int,
    and long variables, both signed and unsigned, by printing appropriate values 
    from standard headers and by direct computation

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-10
*/
#include <stdio.h>

int main()
{
    int i, lim = 100, c;
    /* original for loop
    for (i = 0; i < lim-1 && (c = getchar()) != '\n' && c != EOF; ++i) {
        s[i] = c;
    }
    */

    // use the if statement
    for (i = 0; i < lim-1; ++i) {
        if ((c = getchar()) != '\n') {
            if (c != EOF) {

            }
        }
    }

    return 0;
}