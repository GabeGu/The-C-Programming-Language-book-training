/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 4.3  Write a recursive version of the function reverse(s), 
    which reverses the string s in place

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-28
*/
#include <stdio.h>
#include <string.h>

void reverseR(char s[], int i);

int main()
{
    char s[] = "abcdef";

    printf("%s", s);
    reverseR(s, 0);
    printf("%s", s);
    return 0;
}

/* the recursive version of the function reverse(s) */
void reverseR(char s[], int i) 
{
    int len = strlen(s);
    if (i > (len / 2 - 1)) {
        return;
    }
    char tmp = s[i];
    s[i] = s[len - 1 - i];
    s[len - 1 - i] = tmp;
    reverseR(s, ++i);
}