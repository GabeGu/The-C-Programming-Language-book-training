/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 1.8. Write a program to count blanks, tabs, and newlines.

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-3-29
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

main() {
    int c;// not type of char, because type of int contains the value of EOF(commonly -1)
    long nCount = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ') {// blank
            nCount++;
        }
        else if (c == '\t'){// tab
            nCount++;
        }
        else if (c == 26) {// control-Z
            printf("the number of blanks, tabs, and newlines is:%ld\n", nCount);
            nCount = 0;// terminate of text string, clear the counter for the next input
        }
        else if (c == '\n') {// newlines
            nCount++;
            printf("the number of blanks, tabs, and newlines is:%ld\n", nCount);
            nCount = 0;// end of text string, clear the counter for the next input
        }
    }
    printf("EOF is inputed, stop running\n");
}

