/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 2.5  Write the function any(s1, s2), which returns the first 
    location in the string s1 where any character from the string s2 occurs, 
    or -1 if s1 contains no characters from s2. (The standard library function 
    strpbrk does the same job but returns a pointer to the location.

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-16
*/
#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);
bool isMatchS2(char c, char s2[], int len);

int main()
{
    int len1, len2, i, a_location;
    char s1[MAXLINE], s2[MAXLINE];

    while((len1 = getLine(s1, MAXLINE)) > 0) {
        printf("s1:%s", s1);
        while((len2 = getLine(s2, MAXLINE)) > 0) {
            i = 0;
            printf("s2:%s", s2);
            while (s1[i] != '\0') {
                if (isMatchS2(s1[i], s2, len2)) {
                    a_location = i;
                    break;
                }
                i++;
            }
            if (s1[i] != '\0') {
                printf("the first location of char that matches s2 in the s1 is:%d\n", a_location);
            }
            else {
                printf("there is no matched char that matches s2 in the s1\n");
            }
            break;
        }
    }
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

bool isMatchS2(char c, char s2[], int len)
{
    for (int i = 0; i < len; i++) {
        if (c == '\n') return false;
        if (c == s2[i]) {
            return true;
        }
    }
    return false;
}