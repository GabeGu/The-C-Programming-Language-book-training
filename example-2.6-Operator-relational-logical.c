/* 
    <The C programming language> - 2nd Edition by K&R
    Example 2.6: Relational and logical operators

    compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-10
*/
#include <stdio.h>

int main()
{
// relational operator -----------------------------------------
    printf("%d %d\n", 1 == 1, 1 != 1);
    printf("%d %d %d %d\n", 1 > 1, 1 >= 1, 1 < 1, 1 <= 1);

// logical operator -----------------------------------------
    printf("%d %d %d\n", 1 && 1, 0 || 0, !0);

// precedence and associativity
    printf("%d\n", 1 == 2 > 1);// equal to 1 == (2 > 1)
    printf("%d\n", (1 == 2) > 1);

    printf("%d\n", 1 == 2 - 1);// equal to 1 == (2 - 1)
    printf("%d\n", (1 == 2) - 1);
    return 0;
}