/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <stdio.h>
#include <math.h>
#define NMAX 29

int input(int *data, int *n);
double mean(int *data, int n);
double variance(int *data, int n);
int result(int *data, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) 
        printf("%d", result(data, n));
    else
        printf("n/a");

    return 0;
}

int input(int *data, int *n)
{
    int flag = 1;
    if ((scanf("%d", n) == 1) && (*n > 0) && (*n <= NMAX + 1) && (getc(stdin) == '\n')) {
        for (int *p = data; p - data < *n; p++) {
            if ((scanf("%d", p) != 1) && (getc(stdin) != ('\n' || ' ')))
                flag = 0;
        }
    } else flag = 0;

    return flag;
}

double mean(int *data, int n)
{
    double mean_v = 0;
    for (int *p = data; p - data < n; p++) mean_v += *p;

    return (mean_v / n);
}

double variance(int *data, int n) 
{
    int array[NMAX];
    for (int *p = data; p - data < n; p++) 
        array[p - data] = (*p) * (*p);

    return (mean(array, n) - mean(data, n) * mean(data, n)); 
}

int result(int *data, int n) 
{   
    int var = 0;
    for (int *p = data; p - data < n; p++) {
        if ((*p % 2 == 0) && (*p >= mean(data, n)) && (*p <= mean(data, n) + 3 * sqrt(variance(data, n)))) {
            var = *p;
            break;
        }
    } 

    return var;
}