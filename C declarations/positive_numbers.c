#include <stdio.h>

int main()
{
    float numbers[5];
    int i, posctr = 0;
    double average_value, total = 0;
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

    for (i = 0; i < 5; i++)
    {
        if(numbers[i] > 0)
        {
            posctr++;
            total += numbers[i];
        }
    }
    average_value = total / posctr;
    printf("Positive numbers: %d", posctr);
    printf("\nAverage of all positive numbers: %.2f", average_value);

    return 0;   
}