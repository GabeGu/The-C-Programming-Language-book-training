/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 1.9. Write a program to copy its input to its output, replacing each 
    string of one or more blanks by a single blank.

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-3-29
*/
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int c, lastC;
    bool restart = true;

    lastC = -1;
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == 26) {// terminate of text string
            if (!restart) {
                printf("\n");
            }
            /* init for the next input */
            lastC = -1;
            restart = true;
        }
        else {
            if (restart) {
                printf("after replacing by a single blank: ");
                restart = false;
            }
            if (lastC == ' ') {// ignore the following blanks
                if (c != ' ') {
                    putchar(c);
                    lastC = -1;
                }
            }
            else {
                if (c == ' ') {// record the first blank
                    lastC = c;
                }
                putchar(c);
            }
        }
    }
    printf("EOF is inputed, exit\n");

    return 0;
}