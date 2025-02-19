#include <stdio.h>
#include <math.h>

int main()
{
    double x, result;
    printf("Enter a number: ");
    scanf("%lf", &x);

    result = sin(1/x);

    printf("Value of sin(1/x) is %.4f", result);

    return 0;
}