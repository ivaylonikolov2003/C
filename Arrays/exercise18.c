#include <stdio.h>

int main()
{
    int n, i, j;

    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n][n], arr1[n][n], arr2[n][n];

    printf("Input the elements in the first matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("element - [%d],[%d] : ", i, j);
            scanf("%d", &arr[i][j]);
        }   
    }
    
    printf("Input the elements in the second matrix: \n");
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
            arr2[i][j] = arr[i][j] - arr1[i][j];
        }
        
    }
    
    printf("\nThe substraction of the two matrix is: ");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr2[i][j]);
        }
        
    }
    
    
}