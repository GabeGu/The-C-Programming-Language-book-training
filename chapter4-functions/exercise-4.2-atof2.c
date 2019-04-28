/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 4.2  Extend atof to handle scientific notation of the form
    123.45e-6 where a floating-point number may be followed by e or E and 
    an optionally signed exponent

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-26
*/
#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define MAXLINE 100

int main()
{
    double sum, atof(char []);
    char line[MAXLINE];
    int getline2(char line[], int max);

    while (getline2(line, MAXLINE) > 0) {
        sum = 0;
        printf("\t%g\n", sum += atof(line));
    }
    return 0;
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

double atof(char s[])
{
    double val, power;
    int i, sign, sign2, expon;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] =='-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+') {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
    }
    if (s[i] == '-') {
        i++;
        sign2 = -1;
    }
    for (expon = 0; isdigit(s[i]); i++) {
        expon = expon * 10 + (s[i] - '0');
    }
    if (sign2 == -1) {
        power *= pow(10, expon);
    }
    else {
        power /= pow(10, expon);
    }

    return sign * val / power;
}