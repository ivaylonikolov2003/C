#include <stdio.h>

int main()
{
    int n, i, j, k;

    printf("Enter a number of elements in the array: ");
    scanf("%d", &n);

    int arr1[n];

    for (i = 0; i < n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &arr1[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (arr1[j] >= arr1[j + 1])
            {
                k = arr1[j + 1];
                arr1[j + 1] = arr1[j];
                arr1[j] = k;
            }
            
        }
        
    }

    printf("Array in the ascending order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
    

    return 0;
}