#include <stdio.h>

int main()
{
    int number, positive_value = 0, min_value, max_value, sum = 0;
    double avg_value = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    if(number <= 0)
    {
        printf("No positive number entered!\n");
        return 0;
    }

    min_value = number;
    max_value = number;
    while (number > 0)
    {
        sum += number;
        positive_value++;
        max_value = (number > max_value) ? number : max_value;
        min_value = (number < min_value) ? number : min_value;
        printf("Enter next positive integer: ");
        scanf("%d", &number);
    }
    
    avg_value = sum / (double) positive_value;
    printf("Number of positive values is %d\n", positive_value);
    printf("Maximum value is %d\n", max_value);
    printf("Minimum value is %d\n", min_value);
    printf("Average value is %0.4lf\n", avg_value);

    return 0;
}