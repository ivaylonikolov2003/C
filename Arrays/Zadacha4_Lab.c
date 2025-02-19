#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main()
{
    int n, i, sum = 0, diff = INT_MAX;
    double avg_value = 0;

    printf("Enter a value of the array: ");
    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++)
    {
        printf("Enter a number between [-5000 to 5000]: ");
        scanf("%d", &arr[i]);
        if (arr[i] < -5000 || arr[i] > 5000)
        {
            printf("\nInvalid value!");
        }
        
    }
    int max = arr[0];
    int index = 0;
    for (i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    
    avg_value = ((double)sum / n);

    for (i = 0; i < n; i++)
    {
        if (abs(avg_value - arr[i]) < diff)
        {
            diff = abs(avg_value - arr[i]);
            max = avg_value;
            index = i + 1;
        }
        
    }
    
    printf("Average value is %.2lf, nearest value is %d, index is %d", avg_value, max, index);

    return 0;
}