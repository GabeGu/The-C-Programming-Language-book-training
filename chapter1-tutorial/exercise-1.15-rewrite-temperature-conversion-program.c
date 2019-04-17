/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to
    use a function for conversion

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-8
*/
#include <stdio.h>

/* symbolic constants make the number more meaningful and to be changed systematically */
#define LOWER 0
#define UPPER 300
#define STEP  20

float fahrToCels(int);

main() {
    int lower, upper, step;
    float fahr;

    /* fahrenheit to celsius */
    lower = 0;
    upper = 300;
    step  = 20;
    fahr  = lower;// the intger "lower" is converted to float type before operation is done
    
    printf("fahr       cels\n");
    while (fahr <= upper) {
        printf("%4.0f %10f\n", fahr, fahrToCels(fahr));
        fahr = fahr + step;
    }

    /* for loop version of fahrenheit to celsius */
    printf("fahr       cels\n");
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        printf("%4.0f %10f\n", fahr, fahrToCels(fahr));
    }
}

float fahrToCels(int fahr) 
{
    float cels;
    cels = 5.0 / 9 * (fahr - 32);

    return cels;
}