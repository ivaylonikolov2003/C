#include <stdio.h>

int main()
{
    int n, i, j;

    printf("Input size of the square matrix: ");
    scanf("%d", &n);

    int arr[n][n];
    int arr1[n][n];
    int arr2[n][n];

    printf("Input elements in the first matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("element - [%d],[%d] : ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Input elements in the second matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("element - [%d],[%d] : ", i, j);
            scanf("%d", &arr1[i][j]);
        }
    }
    
    printf("\nThe first matrix is: ");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        
    }

    printf("\nThe second matrix is: ");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr1[i][j]);
        }   
    }
       
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            arr2[i][j] = arr[i][j] + arr1[i][j];     
        }
    }
    
    printf("\nThe addition of two matrix is: ");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr2[i][j]);
        }
        
    }
    
    
}