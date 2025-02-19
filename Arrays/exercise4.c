#include <stdio.h>

int main()
{
    int n, i;
    printf("Enter number of values in array: ");
    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++)
    {
        printf("element - %d ", i);
        scanf("%d", &arr[i]);
    }
    
    printf("The value stores in the array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    printf("\nThe values store in the array in reverse order is: ");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    

}