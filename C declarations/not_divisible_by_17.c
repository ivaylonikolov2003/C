#include <stdio.h>

int main()
{
    int num1, num2, i, sum = 0;
    printf("Enter first integer: ");
    scanf("%d", &num1);
    printf("Enter second integer: ");
    scanf("%d", &num2);

    for (i = num1; i <= num2; i++)
    {
        if(i % 17 != 0)
        {
            sum += i;
        }
    }
    
    printf("%d", sum);
    
    return 0;

}