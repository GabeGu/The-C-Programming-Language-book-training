/* 
    <The C programming language> - 2nd Edition by K&R
    Example 3.3: C preprocessor

    compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-28
*/
#include <stdio.h>

#define max(a, b)   ((a) > (b) ? (a) : (b))
#define dprintf(expr)   printf(#expr" = %d\n", expr)
#define S1 "abc"
#define S2 "efg"
#define paste(front, back)  front ## back

int main()
{
    char c[] = S1""S2;

    printf("%s\n", c);
    printf("%d\n", max(1, 2));
    dprintf(1/2);

    int paste(value, 1) = 1;
    int paste(value, 2) = 2;

    printf("%d %d\n", paste(value, 1), paste(value, 2));

    return 0;
}