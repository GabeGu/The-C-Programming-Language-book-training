/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 2.7 Write a function invert(x,p,n) that returns x 
    with the n bits that begin at position p inverted 
    (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-17
*/
#include <stdio.h>

unsigned invert(unsigned x, int p, int n);
unsigned getbits(unsigned x, int p, int n);
void printfbits(unsigned x);

int main()
{
    unsigned x = 0b10101010;

    printfbits(x);
    x = invert(x, 4, 5);
    printfbits(x);

    return 0;
}

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0U << n);
}

unsigned invert(unsigned x, int p, int n)
{
    unsigned msk;

    msk = (~0U >> (8*sizeof(x) - p - 1)) & (~0U << (p + 1 - n));
    return x ^ msk;
}

void printfbits(unsigned x)
{
    printf("0b");
    for(int i = 8*sizeof(x) - 1; i >= 0; i--) {
        printf("%d", getbits(x, i, 1));
    }
    printf("\n");
}