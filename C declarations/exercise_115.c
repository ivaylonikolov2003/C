#include <stdio.h>

int main()
{
    int num1, num2, sum = 0, i, count = 0;
    double avg_value = 0;

    printf("Enter a first num: ");
    scanf("%d", &num1);
    printf("Enter a second num: ");
    scanf("%d", &num2);

    for (i = num1; i <= num2; i++)
    {
        printf("%d ", i);
        
        if(i % num2 == 0)
        {
            printf("\n");
        }
        sum += i;
        count++;
    }
    avg_value = (sum / count);
    printf("Avg Value is %.2lf", avg_value);

    return 0;
}