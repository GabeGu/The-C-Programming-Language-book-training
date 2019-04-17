/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 2.6 Write a function setbits(x,p,n,y) that returns x with 
    the n bits that begin at position p set to the rightmost n bits of y, 
    leaving the other bits unchanged. 

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-17
*/
#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
void printfbits(unsigned x);

int main()
{
    unsigned x = 0b01010111;
    unsigned y = 0b10101000;

    printfbits(x);
    printfbits(y);
    y = setbits(x, 31, 8, y);
    printfbits(y);
}

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0U << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    x = getbits(x, p, n);
    y = y & (~0U << n);// clear the rightmost n bits of y
    return x + y;
}

void printfbits(unsigned x)
{
    printf("0b");
    for(int i = 8*sizeof(x) - 1; i >= 0; i--) {
        printf("%d", getbits(x, i, 1));
    }
    printf("\n");
}