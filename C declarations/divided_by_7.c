#include <stdio.h>

int main()
{
    int num1, num2, i;

    printf("Enter first integer: ");
    scanf("%d", &num1);

    printf("Enter a second integer: ");
    scanf("%d", &num2);

    for(i = num1; i < num2; i++)
    {
        if (i % 7 == 2 || i % 7 == 3)
        {
            printf("%d\n", i);
        }
        
    }

    return 0;
}