#include <stdio.h>

int main()
{
    int numbers[5];
    int i, total = 0;
    printf("Enter a first number: ");
    scanf("%d", &numbers[0]);
    printf("Enter a second number: ");
    scanf("%d", &numbers[1]);
    printf("Enter a third number: ");
    scanf("%d", &numbers[2]);
    printf("Enter a fourth number: ");
    scanf("%d", &numbers[3]);
    printf("Enter a fifth number: ");
    scanf("%d", &numbers[4]);

    for (i = 0; i < 5; i++)
    {
        if((numbers[i] % 2) != 0)
        {
            total += numbers[i];
        }
    }
    printf("\nAverage of all positive numbers: %d", total);

    return 0;
}