#include <stdio.h>
#include <math.h>

int main()
{
    int num1, num2, sum = 0, i, count = 0;
    printf("Enter first num: ");
    scanf("%d", &num1);
    printf("Enter second num: ");
    scanf("%d", &num2);

    for (i = num1; i <= num2; i++)
    {
        sum += i;
    }

    while (sum > 0)
    {
        count++;
        sum = sum / 10;
    }
    
    printf("Number of digits is %d", count);
    return 0;
}