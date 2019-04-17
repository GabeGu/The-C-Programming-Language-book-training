/* 
    <The C programming language> - 2nd Edition by K&R
    Example 1.7: Since C has no exponentiation operator like the ** of Fortran, 
    let us illustrate the mechanics of function definition by writing a function 
    power(m, n) to raise an integer m to a positive integer power n

    compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-8
*/
#include <stdio.h>

int power(int m, int n);
/* the parameter name is optional
int power(int, int);
*/

/* test power function */
int main()
{
    int i;

    for(i = 0; i < 10; i++) {
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    }
    return 0;
}

/* power: raise base to n-th power; n >= 0 */
int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; i++) {
        p = p * base;
    }
    return p;
}

/* call by value: local variable is initialized when the function is called 
int power(int base, int n)
{
    int p;

    for (p = 1; n > 0; n--) {
        p = p * base;
    }
    return p;
}*/