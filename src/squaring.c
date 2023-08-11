#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main()
{
    int n, data[NMAX];
    if (input(data, &n)) {
        squaring(data, n);
        output(data, n);
    } else printf("n/a");

    return 0;
}

int input(int *a, int *n)
{
    int flag = 1;
    if ((scanf("%d", n) == 1) && (*n > 0) && (*n <= NMAX + 1) && (getc(stdin) == '\n')) {
        for (int *p = a; p - a < *n; p++) {
            if ((scanf("%d", p) != 1) && (getc(stdin) != ('\n' || ' ')))
                flag = 0;
        }
    } else flag = 0;

    return flag;
}

void output(int *a, int n)
{   
    printf("%d", a[0]);
    for(int *p = a + 1; p - a < n; p++)
    {
        printf(" %d", *p);
    } 
}

void squaring(int *a, int n)
{
    for(int *p = a; p - a < n; p++)
    {
        *p *= *p;
    }
}


