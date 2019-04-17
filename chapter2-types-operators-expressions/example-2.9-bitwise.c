/* 
    <The C programming language> - 2nd Edition by K&R
    Example 2.9: bitwise operators

    compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-17
*/
#include <stdio.h>

int main()
{
    char a = 0b0011;
    int msk = 0b0101 ;

    // & | ^ operator
    printf("%d\n", a & msk);
    printf("%d\n", a | msk);
    printf("%d\n", a ^ msk);

    // << operator
    printf("%d\n", a << 1);
    printf("%d\n", a << 2);
    printf("%d\n", a << 3);
    printf("%d\n", a << 4);

    // >> operator
    printf("%d\n", a >> 1);
    printf("%d\n", a >> 2);
    printf("%d\n", a >> 3);
    printf("%d\n", a >> 4);

    a = 0b10000001;// negative
    printf("%d\n", a >> 1);// arithmatic shift

    // ~ operator
    a = 0b0011;
    printf("%d\n", ~a);
    printf("%d\n", a & ~msk);

    return 0;
}