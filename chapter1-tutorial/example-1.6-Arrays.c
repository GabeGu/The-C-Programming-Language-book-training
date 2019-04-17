/* 
    <The C programming language> - 2nd Edition by K&R
    Example 1.6: Arrays
    to count the number of occurrences of each digit, of white space 
    characters (blank, tab, newline), and of all other characters.

    compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-3-28
*/
#include <stdio.h>

main()
{
    int c, i, nWhite, nOther;
    int nDigit[10];

    nWhite = nOther = 0;
    for (i = 0; i < 10; i++) {
        nDigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            nDigit[c - '0']++;
        }
        else if (c == ' ' || c == '\t' || c == '\n') {
            nWhite++;
        }
        else {
            nOther++;
        }
        if (c == '\n' || c == 26) {
            printf("digits = ");
            for (i = 0; i < 10; i++) {
                printf(" %d", nDigit[i]);
            }
            printf(", white space = %d, other = %d\n", nWhite, nOther);
        }
    }

    printf("exit");
}