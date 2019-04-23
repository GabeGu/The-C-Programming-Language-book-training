/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 3.2  Write a function escape(s, t) that converts characters 
    like newline and tab into visible escape sequences like \n and \t as it 
    copies the string t to s. Use a switch. Write a function for the other 
    direction as well, converting escape sequencesin to the real characters

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-23
*/
#include <stdio.h>

#define MAX_SIZE 1000

int escape(char s[], char t[]);
int escape2(char s[], char t[]);
int getLine(char line[], int maxline);

int main()
{
    char s[MAX_SIZE], t[MAX_SIZE];
    int len;

    while ((len = getLine(t, MAX_SIZE)) > 0) {
        printf("convert newline and tab into escape squences:\n");
        printf("string t: %s", t);
        escape(s, t);
        printf("string s: %s\n", s);

        printf("convert escape squences into newline and tab:\n");
        printf("string t: %sn", t);
        escape2(s, t);
        printf("string s: %s\n", s);
    }

    return 0;
}

int escape2(char s[], char t[])
{
    int i, j;

    for (i = 0, j = 0; t[i] != '\0'; j++) {
        switch (t[i]) {
            case '\\': {
                i++;
                switch (t[i]) {
                    case '\0': {
                        s[j] = '\\';
                        break;
                    }
                    case 'n': {
                        s[j] = '\n';
                        break;
                    }
                    case 't': {
                        s[j] = '\t';
                        break;
                    }
                    default: {
                        s[j++] = '\\';
                        s[j] = t[i];
                    }
                }
                i++;
                break;
            }
            default : {
                s[j] = t[i++];
                break;
            }
        }
    }
    s[j] = '\0';
    return j;
}

int escape(char s[], char t[])
{
    int i, j;

    for (i = 0, j = 0; t[i] != '\0'; i++) {
        switch (t[i]) {
            case '\n': {
                s[j++] = '\\';
                s[j++] = 'n' ;
                break;
            }
            case '\t': {
                s[j++] = '\\';
                s[j++] = 't' ;
                break;
            }
            default : {
                s[j++] = t[i];
                break;
            }
        }
    }
    s[j] = '\0';
    return j;
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