/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 1.14. Write a program to print a histogram 
    of the frequencies of different characters in its input. 

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-8
*/
#include <stdio.h>
#include <stdbool.h>

#define MAX_N_CHARS 26  // Aa~Zz

int main() {
    int c, row, col, maxHeight = -2, nChars = 0;
    int freq[MAX_N_CHARS];

    for (row = 0; row < MAX_N_CHARS; row++) {
        freq[row] = 0;
    }
    while((c = getchar()) != EOF) {
        nChars++;
        if (c == ' ' || c == '\t' || c == '\n' || c == 26) {
            if (c == '\n' || c == 26) {
                /* calculate the frequence(%) */
                for (row = 0; row < MAX_N_CHARS; row++) {
                    freq[row] = freq[row] * 100 / nChars;
                }
                /* print the horizonal frequence histogram of the first nWords words */
                for (row = 0; row < MAX_N_CHARS; row++) {
                    if (row == 0) {
                        printf("--------------------------------------------------------------------------------------------------------------------------------\n");
                    }
                    printf("%c%c|", row + 'A', row + 'a');
                    for (col = 0; col < freq[row]; col++) {
                        printf("X ");
                    }
                    printf("\n");
                }
                /* print the vertical frequence histogram of the first nWords words */
                for (row = 0; row < MAX_N_CHARS; row++) {
                    if (freq[row] > maxHeight) {
                        maxHeight = freq[row];
                    }
                }
                for (row = maxHeight; row >= -1; row--) {
                    if (row == maxHeight) {
                        printf("--------------------------------------------------------------------------------------------------------------------------------\n");
                    }
                    for (col = 0; col < MAX_N_CHARS; col++) {
                        if (row == -1) {
                            if (col != 0) {
                                printf("  ");
                            }
                            printf("%c%c", col + 'A', col + 'a');
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
                            if (freq[col] >= row) {
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
                        printf("--------------------------------------------------------------------------------------------------------------------------------\n");
                    }
                }
                nChars = 0;
                maxHeight = -2;
                for (row = 0; row < MAX_N_CHARS; row++) {
                    freq[row] = 0;
                }
            }
        }
        else {
            if (c >= 'a' && c <= 'z') {
                freq[c - 'a']++;
            }
            else if (c >= 'A' && c <= 'Z') {
                freq[c - 'A']++;
            }
        }
    }

    return 0;
}
