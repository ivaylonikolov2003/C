#include <stdio.h>

int main()
{
    int n, i;

    printf("Enter a value of the array: ");
    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++)
    {
        printf("Enter a number between [-5000 to 5000]: ", i);
        scanf("%d", &arr[i]);
    }
    
    int max = arr[0];
    for (i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    printf("Max element is: %d", max);
    
}