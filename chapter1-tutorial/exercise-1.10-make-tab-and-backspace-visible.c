/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 1.10. Write a program to copy its input to its output, replacing each
    tab by \t, each backspace by \b, and each backslash by \\. This makes tabs
    and backspaces visible in an unambiguous way

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-3-29
*/
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int c;
    bool restart = true;
    /* unix
	struct termios ts;

	tcgetattr(STDIN_FILENO, &ts);
	ts.c_lflag &= ~ICANON;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &ts);

	//setvbuf(stdin, NULL, _IONBF, 0);
	//setvbuf(stdout, NULL, _IONBF, 0);
    */
    while((c = getchar()) != EOF) {
        if (c == '\n' || c == 26) {
            if (!restart) {
                printf("\n");
            }
            restart = true;
        }
        else {
            if (restart) {
                printf("after making the tabs and backspaces visible:");
                restart = false;
            }
            if (c == '\t') {
                printf("\\t");
            }
            else if (c == 8) {// I have not find the way to input the BS char, for it is interpreted when strike the BS key
                printf("\\b");
            }
            else if (c == '\\') {
                printf("\\\\");
            }
            else {
                printf("%c(%d)", c, c);
            }
        }
    }
    printf("end excute...");

    return 0;
}