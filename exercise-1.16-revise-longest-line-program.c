/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 1.16. Revise the main routine of the longest-line program so it will
    correctly print the length of arbitrarily long input lines, and as much as possible
    of the text. 

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-8
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
        printf("this line's length is:%d\n", len);
        printf("%s", line);
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