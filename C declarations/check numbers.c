#include <stdio.h>

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    (number % 2 != 0) ? printf("The number is Odd") : printf("The number is Even");

    return 0;
}