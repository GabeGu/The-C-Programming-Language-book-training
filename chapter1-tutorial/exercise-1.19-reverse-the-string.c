/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 1.19. Write a function reverse(s) that reverses the character string s. 
    Use it to write a program that reverses its input a line at a time

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-9
*/
#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

int getLine(char line[], int maxline);
void reverseLine(char line[], int length);

/* point longest input line */
main()
{
    int len;                    /* current line length */
    char line[MAXLINE];         /* current input line */

    while ((len = getLine(line, MAXLINE)) > 0) {
        //printf("%s", line);
        reverseLine(line, len);
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

void reverseLine(char line[], int length) 
{
    char swp;

    if (length <= 2) return;// too short, no need to process

    length--;// last char is '\n'
    for (int i = 0; i < length/2; i++) {
        swp = line[i];
        line[i] = line[length - 1 - i];
        line[length - 1 - i] = swp;
    }
}

