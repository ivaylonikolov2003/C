#include <stdio.h>

int main()
{
    int x, y, i, total =0;
    printf("Enter a pair of numbers: \n");
    printf("Enter first number: \n");
    scanf("%d", &x);
    printf("Enter second number: \n");
    scanf("%d", &y);

    if(x < y)
    {
        return 0;
    }

    printf("List of odd numbers: \n");
    for(i = y; i <= x; i++)
    {
        if(i % 2 != 0)
        {
            printf("%d\n", i);
            total += i;
        }
    }
    printf("Sum = %d\n", total);
    return 0;

}