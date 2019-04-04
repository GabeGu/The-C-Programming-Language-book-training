/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 1.13. Write a program to print a histogram of the lengths of words in
    its input. It is easy to draw the histogram with the bars horizontal; a vertical
    orientation is more challenging

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-4
*/
#include <stdio.h>
#include <stdbool.h>

#define MAX_N_WORDS 20

int main() {
    int c, row, col, maxHeight = -2, nWords = 0;
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
                    if (row == 0) {
                        printf("--------------------------------------------------------------------------------------------------\n");
                    }
                    if (row + 1 < 10) {
                        printf("0");
                    }
                    printf("%d|", row + 1);
                    for (col = 0; col < lWord[row]; col++) {
                        printf("X ");
                    }
                    printf("\n");
                }
                /* print the vertical histogram of the first nWords words */
                for (row = 0; row < nWords; row++) {
                    if (lWord[row] > maxHeight) {
                        maxHeight = lWord[row];
                    }
                }
                for (row = maxHeight; row >= -1; row--) {
                    if (row == maxHeight) {
                        printf("--------------------------------------------------------------------------------------------------\n");
                    }
                    for (col = 0; col < nWords; col++) {
                        if (row == -1) {
                            if (col != 0) {
                                printf("  ");
                            }
                            printf("%d", (col + 1) / 10);
                            printf("%d", (col + 1) % 10);
                            printf(" ");
                        }
                        else if (row == 0) {
                            if (col != 0) {
                                printf("--");
                            }
                            printf("---");

                        }
                        else {
                            if (col != 0) {
                                printf("  ");
                            }
                            printf(" ");
                            if (lWord[col] >= row) {
                                printf("X");
                            }
                            else {
                                printf(" ");
                            }
                            printf(" ");
                        }
                    }
                    printf("\n");
                    if (row == -1) {
                        printf("--------------------------------------------------------------------------------------------------\n");
                    }
                }
                nWords = 0;
                maxHeight = -2;
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
