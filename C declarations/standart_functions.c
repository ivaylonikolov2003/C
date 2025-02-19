#include <stdio.h>
#include <math.h>

int main()
{
    int number, result;
    double square;

    printf("Enter a number: ");
    scanf("%d", &number);

    square = sqrt(number);
    result = pow(number, square);

    printf("The result is %d", result);

    return 0;
}