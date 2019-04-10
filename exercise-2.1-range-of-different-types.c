/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 2.1 Write a program to determine the ranges of char, short, int,
    and long variables, both signed and unsigned, by printing appropriate values 
    from standard headers and by direct computation

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-9
*/
#include <stdio.h>

int main()
{
    char a_c = 0;
    int a_int = 0;
    short a_short = 0;
    long a_long = 0;
    float a_float = 0.0;
    double a_double = 0.0;
    long double a_ld = 0.0;

    char next_c = a_c + 1;
    while (a_c < next_c) {
        a_c++;
        next_c++;
    }
    printf("max of char = %d\n", a_c);
    a_c++;// cause reverse
    printf("min of char = %d\n", a_c);

    short next_short = a_short + 1;
    while (a_short < next_short) {
        a_short++;
        next_short++;
    }
    printf("max of short = %d\n", a_short);
    a_short++;// cause reverse
    printf("min of short = %d\n", a_short);

    int next_int = a_int + 1;
    while (a_int < next_int) {
        a_int++;
        next_int++;
    }
    printf("max of int = %d\n", a_int);
    a_int++;// cause reverse
    printf("min of int = %d\n", a_int);

    long next_long = a_long + 1;
    while (a_long < next_long) {
        a_long++;
        next_long++;
    }
    printf("max of long = %d\n", a_long);
    a_long++;// cause reverse
    printf("min of long = %d\n", a_long);

    return 0;
}