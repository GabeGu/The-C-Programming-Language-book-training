/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 1.5. Modify the temperature conversion program to print the table 
    in reverse order, that is, from 300 degrees to O.

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-3-28
*/
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

int main() {
    float fahr;

    /* for loop version of fahrenheit to celsius */
    printf("fahr       cels\n");
    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
        printf("%4.0f %10f\n", fahr, 5.0 / 9 * (fahr - 32));
    }

    return 0;
}
