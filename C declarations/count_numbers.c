#include <stdio.h>

int main()
{
    float numbers[5];
    int i, posctr = 0, negctr = 0;
    printf("Enter a first number: ");
    scanf("%f", &numbers[0]);
    printf("Enter a second number: ");
    scanf("%f", &numbers[1]);
    printf("Enter a third number: ");
    scanf("%f", &numbers[2]);
    printf("Enter a fourth number: ");
    scanf("%f", &numbers[3]);
    printf("Enter a fifth number: ");
    scanf("%f", &numbers[4]);

    for(i = 0; i < 5; i++)
    {
        if (numbers[i] > 0)
        {
            posctr++;
        }
        else if (numbers[i] < 0)
        {
            negctr++;
        }
    }
    printf("Positive numbers: %d", posctr);
    printf("\nNegative numbers: %d", negctr);
    return 0;
}