/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 1.13. Write a program that prints its input one word per line. 

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-2
*/
#include <stdio.h>
#include <stdbool.h>

#define MAX_N_WORDS 20

int main() {
    int c, row, col, nWords = 0;
    int lWord[MAX_N_WORDS];
    bool inTheWord = false;

    /* calculate the length of the first nWords words */
    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n' || c == 26) {
            if (inTheWord) {
                inTheWord = false;
                if (nWords < MAX_N_WORDS) {
                    nWords++;// pointer to next subscript of array
                }
            }
            /* print the horizonal histogram of the first nWords words */
            if (c == '\n' || c == 26) {
                for (row = 0; row < nWords; row++) {
                    if (row + 1 < 10) {
                        printf("0");
                    }
                    printf("%d|", row + 1);
                    for (col = 0; col < lWord[row]; col++) {
                        printf("X");
                    }
                    printf("\n");
                }
                nWords = 0;
            }
        }
        else {
            if (!inTheWord) {
                inTheWord = true;
                lWord[nWords] = 0;
            }
            if (nWords < MAX_N_WORDS) {
                lWord[nWords]++;
            }
        }
    }

    return 0;
}
