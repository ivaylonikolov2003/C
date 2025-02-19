#include <stdio.h>

int main()
{
    int num1, num2;
    int *pt1 = &num1, *pt2 = &num2;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    if (*pt1 > *pt2)
    {
        printf("Maximum number is %d", *pt1);
    }
    else
    {
        printf("Maximum number is %d", *pt2);
    }
    
    return 0;

}