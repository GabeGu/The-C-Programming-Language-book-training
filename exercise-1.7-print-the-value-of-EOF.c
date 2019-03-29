/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 1.7. Write a program to print the value of EOF

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-3-28
*/
#include <stdio.h>

int main() {
    printf("%d\n", EOF);

    return 0;

    /*
        Answer: the value of EOF in windows is -1.
    */
}