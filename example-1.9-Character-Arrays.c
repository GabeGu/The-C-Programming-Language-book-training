/* 
    <The C programming language> - 2nd Edition by K&R
    Example 1.9: To illustrate the use of character arrays and functions to manipulate them, 
    let's write a program that reads a set of text lines and prints the longest.

    compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-8
*/
#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/* point longest input line */
main()
{
    int len;                    /* current line length */
    int max;                    /* maximum length seen so far */
    char line[MAXLINE];         /* current input line */
    char longest[MAXLINE];      /* longest line saved here */

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {
        printf("%s", longest);
    }
    return 0;
}

int getLine(char s[], int lim)
{
    int c, i;

    for (i = 0; (i < lim - 1) && ((c = getchar()) != EOF) && (c != '\n'); i++) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}