/* 
    <The C programming language> - 2nd Edition by K&R
    Example 3.3: Binary Search

    compiler: MinGW.org GCC-8.2.0-3
    by Gabe Gu
    2019-4-22
*/
#include <stdio.h>

#define N 10

int binsearch(int x, int v[], int n);

int main()
{
    int v[N];

    printf("array v is: ");
    for (int i = 0; i < N; i++) {
        v[i] = i + 3;
        printf("%d ", v[i]);
    }
    int x = 3;
    printf("\nfind %d in array v: \n", x);
    if (binsearch(x, v, N) != -1) {
        printf("x is found");
    }
    else {
        printf("x is not found");
    }

    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        }
        else if (x > v[mid]) {
            low = mid + 1;
        }
        else {      // found match
            return mid;
        }
    }
    return -1;      // no match
}