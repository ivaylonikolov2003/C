#include <stdio.h>

int main()
{
    int number, sum = 0, i;

    printf("Enter a positive number less than 500: ");
    scanf("%d", &number);

    if(number < 1 || number > 500)
    {
        printf("Invalid input");
    }
    else
    {
        for (i = 1; i <= 3; i++)
        {
            sum += number % 10;
            number /= 10;
        }
    }

    printf("Sum is %d", sum);

    return 0;
}