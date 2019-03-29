/* 
    <The C programming language> - 2nd Edition by K&R
    Example 1.5: Character Input and Output
    copy input to output one character at a time:
    //----------------------------------------------------
        read a character
            while (character is not end-of-file indicator)
            output the characterjust read
            read a character
    //----------------------------------------------------

    compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-3-28
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

main() {
    int c;// not type of char, because type of int contains the value of EOF(commonly -1)
    double nChars = 0;

    /* 1.5.1: file copy; 1st version
    c = getchar();
    while (c != EOF) {
        putchar(c);
        printf("in processing...\n");// for test
        c = getchar();
    } */ 

    /* 1.5.1: file copy; 2nd version: 
       assignment "c = getchar()" as a part of the expression which is more compact
    while ((c = getchar()) != EOF) {
        putchar(c);
        printf("in processing...\n");// for test
    } */

    /* character counting and output the char string */
    bool restart = true;
    while((c = getchar()) != EOF) {
        if (c == '\n' || c == 26) {// end of the text. see the comment below
            printf("\n");
            printf("the number of char string is: %.0f\n", nChars);
            restart = true;
            nChars = 0;
        }
        else {
            if (restart) {
                restart = false;
                printf("the input char string is    : ");
            }
            putchar(c);
            nChars++;
        }
    }
    printf("EOF is inputed, stop running\n");

    /* Test reason for reaching EOF. */
    if (feof(stdin)) {         // if failure caused by end-of-file condition
       puts("End of file reached");
    }
    else if (ferror(stdin))   // if failure caused by some other error
    {
       perror("getchar()");
       fprintf(stderr,"getchar() failed in file %s at line # %d\n", __FILE__,__LINE__-9);
       exit(EXIT_FAILURE);
    }

    /* in windows terminal, if char '^Z'(ASCII 26) is input first, the getchar() will return the EOF indicator
       (it may confuse us that the '^Z' is treated as equal to EOF, but actually is not);
       if '^Z' is followed some chars like "123^Zabc", their is no EOF returned by getchar() and 4 chars was get 
       which is '1' '2' '3' '^Z', so it seems like the '^Z' char is interpreted as end of the text stream but the 
       value is not equal to the EOF(commonly -1).
       in other words, we should judge this cahr '^Z'(ASCII 26) if we want to process the input char string like 
       counting the numbers of input chars 
    */
}