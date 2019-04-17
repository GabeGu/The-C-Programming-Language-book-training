/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 2.3  Write the function htoi(s), which converts a string of 
    hexadecimal digits (including an optional Ox or ox) into its equivalent 
    integer value. The allowable digits are 0 through 9, a through f, and A through F

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-15
*/
#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 1000    /* maximum input line size */

int getLine(char line[], int maxline);

int main()
{
    int len;                    /* current line length */
    char line[MAXLINE];         /* current input line */
    unsigned int a_value = 0;
    bool isInvalidDigit = false, inPaddingZero = true;

    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > 1/*\n*/) {
            int i = 0;
            // process the optional "0x" or "0X"
            if (len > 3) {
                if (line[0] == '0' && (line[1] == 'x' || line[1] == 'X')) {
                    i = 2;
                }
            }
            // process the padding zero
            while (line[i] != '\n') {
                if (line[i] != '0') {
                    inPaddingZero = false;
                    break;
                }
                i++;
            }
            // calculate the value
            if (!inPaddingZero) {
                unsigned int a_size = 0;
                while (line[i] != '\n') {
                    unsigned int c_value;
                    a_size++;
                    // char to integer value
                    if (line[i] >= '0' && line[i] <= '9') {
                        c_value = line[i] - '0';
                    }
                    else if (line[i] >= 'a' && line[i] <= 'f') {
                        c_value = line[i] - 87;
                    }
                    else if (line[i] >= 'A' && line[i] <= 'F') {
                        c_value = line[i] - 55;
                    }
                    else {
                        isInvalidDigit = true;
                        break;
                    }
                    if (a_size <= 2*sizeof(int)) {
                        a_value = (a_value << 4U) + c_value;
                    }
                    i++;
                }
            }
        }
        else {
            isInvalidDigit = true;
        }
        // print the result
        if (isInvalidDigit) {
            printf("invalid string of hexademical digits\n");
        }
        else {
            printf("intefer value is: %u\n", a_value);
        }
        // initialize the data
        isInvalidDigit = false;
        inPaddingZero = true;
        a_value = 0;
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