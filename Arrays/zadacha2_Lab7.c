#include <stdio.h>

int main()
{
    int n, i, j;
    int diagonal_sum = 0, row_sum = 0, col_sum = 0;
    int count = 0;

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

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                diagonal_sum += arr[i][j]; 
            }
        }
    }
    
    for (i = 0; i < n; i++)
    {
        row_sum = 0;
        for (j = 0; j < n; j++)
        {
            row_sum += arr[i][j];
        }
        if (diagonal_sum == row_sum)
        {
            count = 1;
        }
        else
        {
            count = 0;
            break;
        }
    }

    for (i = 0; i < n; i++)
    {
        col_sum = 0;
        for (j = 0; j < n; j++)
        {
            col_sum += arr[i][j];
        }
        if (diagonal_sum == col_sum)
        {
            count = 1;
        }
        else
        {
            count = 0;
            break;
        }
    }
    
    if (count == 1)
    {
        printf("\nEntered matrix is a magic square");
    }
    else
    {
        printf("\nEntered matrix is not a magic square");
    }

    return 0;   
}