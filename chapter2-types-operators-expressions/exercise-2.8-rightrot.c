/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 2.8  Write a function rightrot(x,n) that returns the 
    value of the integer x rotated to the right by n bit positions

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-18
*/
#include <stdio.h>

unsigned rightrot(unsigned x, int n);
unsigned getbits(unsigned x, int p, int n);
void printfbits(unsigned x);

int main()
{
    unsigned x = 0b010110111011110111110111111;
    printfbits(x);
    x = rightrot(x, 1);
    printfbits(x);

    return 0;
}

unsigned rightrot(unsigned x, int n) 
{
    /* version one: loop for n times, every time right rotate a bit
    for (; n > 0; n--) {
        x = (x >> 1U) | (x << (8*sizeof(x) - 1));
    }
    */
    /* version two: right ratate only once, need to process when n > 8*sizeof(x) */
    n %= 32;
    if (n == 0) {// no need to ratate
        return x;
    }
    x = (x >> (unsigned)n) | (x << (8*sizeof(x) - n));

    return x;
}


unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0U << n);
}

void printfbits(unsigned x)
{
    printf("0b");
    for(int i = 8*sizeof(x) - 1; i >= 0; i--) {
        printf("%d", getbits(x, i, 1));
    }
    printf("\n");
}