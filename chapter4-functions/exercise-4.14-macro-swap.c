/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 4.3  Define a macro swap(t,x,y) that interchanges two arguments of type t. 
    (Block structure will help)

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-28
*/
#include <stdio.h>

#define swap(t, x, y)   {\
    t tmp;\
    tmp = x, x = y, y = tmp;\
}

int main()
{
    int x, y;
    double m, n;

    x = 1, y = 2;
    m = 1.1, n = 2.1;

    swap(int, x, y);
    printf("%d %d\n", x, y);
    swap(double, m, n);
    printf("%.2f %.2f\n", m, n);

    return 0;
}