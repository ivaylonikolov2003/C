#include <stdio.h>

int main()
{
    int n, i;

    printf("Input the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    int arr2[n];

    for (i = 0; i < n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        arr2[i] = arr[i];
    }
    
    printf("\nElements stored in first array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    printf("\nElements stored in second array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr2[i]);
    }
    

}