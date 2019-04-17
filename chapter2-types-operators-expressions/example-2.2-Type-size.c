/* 
    <The C programming language> - 2nd Edition by K&R
    Example 2.2: diffrent size of types

    compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-10
*/
#include <stdio.h>

int main()
{
    // char type
    char a_c = 0;

    // int type
    int a_int = 0;
    short a_short = 0;
    long a_long = 0;

    // floatint-point type
    float a_float = 0.0;
    double a_double = 0.0;
    long double a_ld = 0.0;

    printf("%d %d %d %d %d %d %d\n", sizeof(a_c), sizeof(a_short), sizeof(a_int), 
                sizeof(a_long), sizeof(a_float), sizeof(a_double), sizeof(a_ld));

    return 0;
}