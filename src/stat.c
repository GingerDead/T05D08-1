#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);

int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main()
{
    int n, data[NMAX];
    if (input(data, &n)) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
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
    for(int *p = a; p - a < n; p++)
        (p - a != n - 1) ? printf("%d ", *p) : printf("%d\n", *p);
}

int max(int *a, int n)
{
    int max_v = a[0];
    for(int *p = a + 1; p - a < n; p++)
        if (max_v < *p)
            max_v = *p;

    return max_v;
}

int min(int *a, int n)
{
    int min_v = a[0];
    for(int *p = a + 1; p - a < n; p++)
        if (min_v > *p)
            min_v = *p;

    return min_v;
}

double mean(int *a, int n)
{
    double mean_v = 0;
    for (int *p = a; p - a < n; p++) mean_v += *p;

    return (mean_v / n);
}

double variance(int *a, int n) 
{
    int data[NMAX];
    for (int *p = a; p - a < n; p++) 
        data[p-a] = (*p) * (*p);

    return (mean(data, n) - mean(a, n) * mean(a, n)); 
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) 
{
    printf("%d %d %.6f %.6f", max_v, min_v, mean_v, variance_v);
}