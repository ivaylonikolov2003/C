#include <stdio.h>

int main()
{
    int n, i;

    printf("Enter a value of the array: ");
    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++)
    {
        printf("element -  %d : ", i);
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    int min = arr[0];
    for (i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    for (i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        
    }
    

    printf("Max element is: %d", max);
    printf("\nMin element is: %d", min);
    
}