/* 
    <The C programming language> - 2nd Edition by K&R
    Example 2.4: Declarations

    compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-10
*/
#include <stdio.h>

// external variable
int e_lower;
int e_upper = 2;
static int e_step;
const char e_c;
static const float e_eps = 1.0;

int main()
{
    // lists
    int lower, upper, step;
    char c, line[1000];

    // another fashion
    int lower1;// convevient for adding comments
    int upper1;
    int step1;
    char c1;
    char line1[1000];

    printf("the value of automatic variable with no initialization is undefined: %d\n", lower);
    printf("the value of external variable with no initialization is zero: %d\n", e_lower);

    // with initialization
    int esc = '\\';
    int i = 0, j = 1;
    float eps = 1.0e-5;
    printf("%c %d %f", esc, i, eps);

    /* change to a const variable can cause an error
    e_c = 1;
    printf("%d\n", e_c);
    */
}