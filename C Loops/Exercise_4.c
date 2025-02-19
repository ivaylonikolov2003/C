#include <stdio.h>

int main()
{
    int num, n, i, sum = 0;
    double avg_value;

    printf("Enter a value of n: ");
    scanf("%d", &n);


    for (i = 0; i < n; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &num);

        sum += num;
    }

    avg_value = (sum / (double)n);

    printf("The sum is %d\n", sum);
    printf("Average value is %f", avg_value);
    
    return 0;
}