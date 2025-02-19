#include <stdio.h>

int main()
{
    int x, y;
    double result = 0.0;
    printf("Enter first number: ");
    scanf("%d", &x);
    printf("Enter second number: ");
    scanf("%d", &y);

    if (x % y == 0)
    {
        result = x / y;
        printf("%.2f", result);
    }
    else
    {
        printf("Division not possible");
    }

    return 0;
}