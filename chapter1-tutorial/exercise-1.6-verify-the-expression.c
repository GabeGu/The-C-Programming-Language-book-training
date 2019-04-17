/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 1.6. Verify the expression: getchar() != EOF is 0 or 1

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-3-28
*/
#include <stdio.h>

int main() {
    while (getchar() != EOF) {
        printf("in processing...\n");// for test
    } 

    printf("EOF is inputed, stop running\n");// in windows "^Z" represent the EOF

    return 0;
    /*
        Answer: 
            if input "123", it will print test string "in processing..." 4 times
            if input '^z'(is equal to EOF in windows), it will print "EOF is inputed, stop running" 
        so when the char is EOF, the expression's value is 0; otherwise is 1.
    */
}