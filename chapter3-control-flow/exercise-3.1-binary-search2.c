/* 
    <The C programming language> - 2nd Edition by K&R
    Exercise 3.1  Our binary search makes two tests inside the loop, when one 
    would suffice(at the price of more tests outside). Write a version with only 
    one test inside the loop and measure the difference in run-time

    Compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-23
*/
#include <stdio.h>

#define N 10

int binsearch2(int x, int v[], int n);

int main()
{
    int x = 19;
    int v[N];

    printf("array v is: ");
    for (int i = 0; i < N; i++) {
        v[i] = 2 * i;
        printf("%d ", v[i]);
    }
    printf("\nfind %d in array v: \n", x);
    if (binsearch2(x, v, N) != -1) {
        printf("x is found");
    }
    else {
        printf("x is not found");
    }

    return 0;
}

int binsearch2(int x, int v[], int n)
{
    int low, mid, high;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid]) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    if (x == v[mid]) {
        return mid;
    }
    else {
        return -1;
    }
}