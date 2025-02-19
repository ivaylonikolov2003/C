#include <stdio.h>

int main()
{
    int i, j, num1, num2, sum = 0;

    printf("Enter first num: ");
    scanf("%d", &num1);
    printf("Enter second num: ");
    scanf("%d", &num2);

    if(num1 > num2)
    {
        for (i = num2; i >= num1; i--)
        {
            printf("%d", i);
            if(i % 7 != 0)
            {
                sum += i;
            }
           
        }
    }
    else if (num1 < num2)
    {
        for (j = num1; j <= num2; j++)
        {
            if(j % 7 != 0)
            {
                sum += j;
            }
        }
        
    }
    printf("Sum is %d", sum);
}