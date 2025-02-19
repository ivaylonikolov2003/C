#include <stdio.h>

int main()
{
    int n, i, j, k, count = 0;

    printf("Enter a number of values in the array: ");
    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }
    printf("\nThe unique elements in the array are: ");
    for (i = 0; i < n; i++)
    {
        count = 0;
        for (j = 0, k = n; j < k + 1; j++)
        {
            if (i != j)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                }
            }
        }
        if (count == 0)
        {
            printf("%d ", arr[i]);
        }
    }
    
}