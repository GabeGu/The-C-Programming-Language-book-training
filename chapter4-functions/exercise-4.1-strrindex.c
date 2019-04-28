/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 4.1   Write the function strrindex (s, t), which returns 
    the position of the rightmost occurrence of t in s, or - 1if there is none

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-26
*/
#include <stdio.h>

#define MAXLINE 1000

int getline2(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main()
{
    char line[MAXLINE];
    int found = 0;

    while (getline2(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    return found;
}

int getline2(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0') {
            printf("%d\n", i + k - 1);
            return i + k - 1;   // the rightmost position of t matched in s
        }
    }
    return -1;
}