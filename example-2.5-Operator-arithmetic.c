/* 
    <The C programming language> - 2nd Edition by K&R
    Example 2.5: Arithmatic operators

    compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-10
*/
#include <stdio.h>
#include <limits.h>

int main()
{
    int x, n_x, y, n_y;

// + operator -----------------------------------------
    x = 1, y = 2, n_x = -1, n_y = -2;
    printf("%d %d %d %d\n", x + y, x + n_y, n_x + y, n_x + n_y);

// - operator -----------------------------------------
    x = 1, y = 2, n_x = -1, n_y = -2;
    printf("%d %d %d %d\n", x - y, x - n_y, n_x - y, n_x - n_y);

// * operator -----------------------------------------
    x = 1, y = 2, n_x = -1, n_y = -2;
    printf("%d %d %d %d\n", x * y, x * n_y, n_x * y, n_x * n_y);

// / operator -----------------------------------------
    x = 10, y = 3, n_x = -10, n_y = -3;
    printf("%d %d %d %d\n", x / y, x / n_y, n_x / y, n_x / n_y);

// % operator -----------------------------------------
    x = 10, y = 3, n_x = -10, n_y = -3;
    // produces the remainder when is not
    // % for a negative operand, the result is machine-dependent
    printf("%d %d %d %d\n", x % y, x % n_y, n_x % y, n_x % n_y);

    // zero when y divides x exactly
    y = 2;
    printf("%d\n", x % y);

    // judge the leap year
    int year = 2019;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        printf("%d is a leap year\n", year);
    }
    else {
        printf("%d is not a leap year\n", year);
    }

    /* % cannot be appied to floatpint-pointing type, it will cause an error
    float a_f = 10.0;
    printf("%d\n", a_f % y);
    */

// precedence and associativity --------------------------------
    printf("%d\n", x + y - x * x / y % y);
    printf("%d\n", (x + y) - (((x * x) / y) % y));

    return 0;
}