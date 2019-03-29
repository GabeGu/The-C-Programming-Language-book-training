/* 
    <The C programming language> - 2nd Edition by K&R
    Example 1.2~1.4: uses the formula C=(5/9)(F-32) to print the table of 
    Fahrenheit temperatures and their centigrade or Celsius equivalent

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-3-28
*/
#include <stdio.h>

/* symbolic constants make the number more meaningful and to be changed systematically */
#define LOWER 0
#define UPPER 300
#define STEP  20

main() {
    int lower, upper, step;
    float fahr, cels;

    /* fahrenheit to celsius */
    lower = 0;
    upper = 300;
    step  = 20;
    fahr  = lower;// the intger "lower" is converted to float type before operation is done
    
    printf("fahr       cels\n");
    while (fahr <= upper) {
        cels = 5.0 / 9 * (fahr - 32);
        printf("%4.0f %10f\n", fahr, cels);
        fahr = fahr + step;
    }

    /* for loop version of fahrenheit to celsius */
    printf("fahr       cels\n");
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        printf("%4.0f %10f\n", fahr, 5.0 / 9 * (fahr - 32));
    }
}
