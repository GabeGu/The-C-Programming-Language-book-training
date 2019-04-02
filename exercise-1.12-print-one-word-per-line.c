/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 1.12. Write a program that prints its input one word per line. 

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-3-29
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    int c;// not type of char, because type of int contains the value of EOF(commonly -1)

    bool restart = true;
    bool inTheWord = false;
    while((c = getchar()) != EOF) {
        if (c == '\n' || c == 26) {// end of the text. see the comment below
            if (!restart) {
                printf("\n");
            }
            restart = true;
            inTheWord = false;
        }
        else {
            if (restart) {
                restart = false;
                printf("the input chars is:\n");
            }

            if (c == ' ' || c == '\t' || c == '\n') {
                if (inTheWord) {
                    printf("\n");
                }
                inTheWord = false;
            }
            else {
                if (!inTheWord) {
                    inTheWord = true;
                }
                putchar(c);
            }
        }
    }
    printf("EOF is inputed, stop running\n");

    return 0;
}