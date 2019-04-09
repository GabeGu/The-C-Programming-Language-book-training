/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 1.18.  Write a program to remove trailing blanks and tabs from each line of input, 
    and to delete entirely blank lines

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-9
*/
#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 1000    /* maximum input line size */

int getLine(char line[], int maxline);
int removeTrailBlankChar(char line[], int length);

/* point longest input line */
main()
{
    int len;                    /* current line length */
    char line[MAXLINE];         /* current input line */

    while ((len = getLine(line, MAXLINE)) > 0) {
        if ((len = removeTrailBlankChar(line, len)) > 0) {
            printf("%s", line);
        }
        //else {
        //    printf("all the chars are blanks, the whole line is removed\n");
        //}
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

int removeTrailBlankChar(char line[], int length)
{
    bool inTrailing = false, hasNewline = false;

    for (--length; length >= 0; length--) {
        if (!inTrailing) {
            if (line[length] == '\n') {
                hasNewline = true;
            }
            else if (line[length] == ' ' || line[length] == '\t') {
                inTrailing = true;
            }
            else {
                length++;
                if (hasNewline) length++;
                return length;
            }
        }
        else {
            if (line[length] != ' ' && line[length] != '\t') {
                length++;
                line[length] = '\n';
                length++;
                line[length] = '\0';
                return length;
            }
        }
    }
    // entirely blank lines
    return 0;
}