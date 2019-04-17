/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 1.17.  Write a program to print all input lines that are longer than 80 characters.

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-9
*/
#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

int getLine(char line[], int maxline);

/* point longest input line */
main()
{
    int len;                    /* current line length */
    char line[MAXLINE];         /* current input line */

    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > 80) {
            printf("this line's length is:%d\n", len);
            printf("%s", line);
        }
    }
    return 0;
}

int getLine(char s[], int lim)
{
    int c, i;

    for (i = 0; (i < lim - 1) && ((c = getchar()) != EOF) && (c != '\n') && (c != 26); i++) {
        s[i] = c;
    }
    if (c == '\n' || c == 26) {
        s[i] = '\n';
        i++;
    }
    s[i] = '\0';
    return i;
}