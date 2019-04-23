/* 
    <The C programming language> - 2nd Edition by K&R
    Example 3.7: Break and Continue

    compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-23
*/
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

int getLine(char s[], int lim);
int trim(char s[]);

int main()
{
    char s[MAX_SIZE];
    int len;

    while ((len = getLine(s, MAX_SIZE)) > 0) {
        printf("string s is: %s(%d)", s, len);
        len = trim(s);
        printf("after trim: %s(%d)\n", s, len);
    }

    return 0;
}

int trim(char s[]) 
{
    int n;

    for (n = strlen(s) - 1; n >= 0; n--) {
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n') break;
    }
    s[n++] = '\0';

    return n;
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