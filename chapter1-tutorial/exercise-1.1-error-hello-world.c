/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 1.1. Run the "hello, world" program on your system. Experiment
    with leaving out parts of the program, to see what error messages you get.

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-3-28
*/
#include <stdio.h>

int main() 
{
    /* miss ";" */
    printf("hello, world\n")

    /* miss a "(" */
    printf"hello, world\n");

    return 0;

    /* 
	    Answer: the compiler will output some error messages 
    */
}