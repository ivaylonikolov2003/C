#include <stdio.h>

int main()
{
    double a, b, c, perimeter;
    printf("Enter a first side: ");
    scanf("%lf", &a);
    printf("Enter a second side: ");
    scanf("%lf", &b);
    printf("Enter a third side: ");
    scanf("%lf", &c);

    if ((a + b > c) && (a + c > b) && (b + c > a))
    {
        perimeter = (a + b + c);
    }

    printf("Perimeter = %.2f", perimeter);

    return 0;
}