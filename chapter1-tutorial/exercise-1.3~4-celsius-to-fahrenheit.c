/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 1.3. Modify the temperature conversion program to print a heading above the table. 
    Exercise 1.4. Write a program to print the corresponding Celsius to Fahrenheit table. 

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-3-28
*/
#include <stdio.h>

/* symbolic constants make the number more meaningful and to be changed systematically */
#define LOWER 0
#define UPPER 100
#define STEP  10

int main() {
    float cels;

    printf("cels    fahr\n");
    for (cels = LOWER; cels <= UPPER; cels += STEP) {
        printf("%4.0f   %5.1f\n", cels, cels * 9.0 / 5.0 + 32.0);
    }

    return 0;
}
