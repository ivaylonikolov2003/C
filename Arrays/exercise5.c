#include <stdio.h>

int main()
{
    int n, i, sum = 0;

    printf("Enter a number of values in array: ");
    scanf("%d", &n);
    int arr[n];

    for (i = 0; i < n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }
    
    for (i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    
    printf("Sum of all elements stored in the array is: %d", sum); 

}