#include <stdio.h>

int main()
{
    int n, i, j;

    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n][n];

    printf("Input the elements in the matrix %d x %d: \n", n, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("element - [%d],[%d] : ", i, j);
            scanf("%d", &arr[i][j]);
        }
        
    }

    printf("\nThe matrix is:");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        
    }
    
    printf("\nElements in the main diagonal are: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                printf("%d ", arr[i][j]);
            }
            
        }
    }

    printf("\nElements in the secondary diagonal are: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if ((i + j) == (n - 1))
            {
                printf("%d ", arr[i][j]);
            }
        }
    }
    
    printf("\nElements above the main diagonal: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j > i)
            {
                printf("%d ", arr[i][j]);
            }
        }
    }
    
    printf("\nElements under the main diagonal: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i > j)
            {
                printf("%d ", arr[i][j]);
            }
        }
    }
    
}