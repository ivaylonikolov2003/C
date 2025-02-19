#include <stdio.h>

int main()
{
    int n, m, k, j, i, x;


    printf("Enter a values of the first array: ");
    scanf("%d", &n);
    int arr1[n];
    for (i = 0; i < n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &arr1[i]);
    }

    printf("Enter a values of the second array: ");
    scanf("%d", &m);
    int arr2[m];
    for (i = 0; i < m; i++)
    {
        printf("element of second array - %d : ", i);
        scanf("%d", &arr2[i]);
    }

    k = m + n;
    int arr3[k];
    for (i = 0; i < n; i++)
    {
        arr3[i] = arr1[i];
    }
    for (j = 0; j < m; j++)
    {
        arr3[i] = arr2[j];
        i++;
    }

    for (i = 0; i < k; i++)
    {
        for (x = 0; x < k - 1; x++)
        {
            if (arr3[x] <= arr3[x + 1])
            {
                j = arr3[x + 1];
                arr3[x + 1] = arr3[x];
                arr3[x] = j;
            }
            
        }
        
    }
    
    printf("The merged array in descending order is:\n");
    for (i = 0; i < k; i++)
    {
        printf("%d ", arr3[i]);
    }

}