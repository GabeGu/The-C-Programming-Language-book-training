/* 
    <The C programming language> - 2nd Edition by K&R
    Example 2.3: diffrent type of constants

    compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-10
*/
#include <stdio.h>
#include <string.h>

int main()
{
    // interger constant
    printf("%d %d %d\n", 1, 011, 0x0F);

    // floating-point constant
    printf("%f %f %f\n", 1.13, 1e2, 1e-2);

    // character constant
    printf("%d %d %d %d %d %d %d\n", '\a', '\b', '\f', '\n', '\r', '\t', '\v');
    printf("%d %d %d %d %d %d   \n", '\\', '\?', '\'', '\"', '\031', '\x1f'  );

    // string constant
    printf("%s %s %s \n%s\n", "hello world", " /* ", "\"hello" " world\"", "\aa \bb \ff \nn \rr \tt \vv \\ \? \' \"");

    const char a[5] = "hello";// in array a, there is no '\0', so the len is not sure
    printf("%d\n", strlen(a));

    // enumeration constant
    enum boolean {
        NO,// implicit 0
        YES = 2,
        YES2
    };
    enum boolean a_bool = NO;
    printf("%d %d %d %d\n", NO, YES, YES2, a_bool);
}