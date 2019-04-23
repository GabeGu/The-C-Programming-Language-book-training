/* 
    <The C programming language> - 2nd Edition by K&R
    Example 3.5: Loops - While and For

    compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-23
*/
#include <ctype.h>
#include <stdio.h>

#define MAX_SIZE 1000

int getLine(char s[], int lim);
int atoi2(char s[]);

int main()
{
    char s[MAX_SIZE];
    int len, value;

    while ((len = getLine(s, MAX_SIZE)) > 0) {
        printf("string s is: %s", s);
        value = atoi2(s);
        printf("converted to integer is: %d\n", value);
    }

    return 0;
}

/* atoi: converts to integer; version 2 */
int atoi2(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++) // skip white space
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') // skip sign
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');

    return sign * n;
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