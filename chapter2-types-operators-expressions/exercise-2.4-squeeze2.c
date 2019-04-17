/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 2.4  Write an alternate version of squeeze(s1, s2) that 
    deletes each character in s1 that matches any character in the string s2

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
    int len1, len2, i, j;
    char s1[MAXLINE], s2[MAXLINE];

    while((len1 = getLine(s1, MAXLINE)) > 0) {
        printf("s1:%s", s1);
        while((len2 = getLine(s2, MAXLINE)) > 0) {
            i = j = 0;
            printf("s2:%s", s2);
            while (s1[i] != '\0') {
                if (!isMatchS2(s1[i], s2, len2)) {
                    s1[j++] = s1[i++];
                }
                else {
                    i++;
                }
            }
            s1[j] = '\0';
            printf("s1:%s", s1);
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