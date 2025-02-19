#include <stdio.h>

int main()
{
    int n, sum = 0, i;

    printf("Input number of terms: ");
    scanf("%d", &n);

    printf("The odd numbers are : ");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", (2 * i) - 1);
        sum += (2 * i) - 1;
    }
    
    printf("\nThe sum of odd natural numbers is: %d", sum);

    return 0;
}