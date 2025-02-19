#include <stdio.h>

int main()
{
    int n, i, j, count = 0;

    printf("Enter a number of values in the array: ");
    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                break;
            }
            
        }
    }
    
    printf("Total numbers of duplicate elements found in the array is: %d", count);
}