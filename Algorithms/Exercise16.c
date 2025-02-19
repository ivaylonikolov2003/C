#include <stdio.h>

int main()
{
    int n, m, row, col, sum = 0;

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter m: ");
    scanf("%d", &m);

    int arr[n][m];

    printf("Enter elements in the array\n");
    for (row = 0; row < n; row++)
    {
        for (col = 0; col < m; col++)
        {
            printf("element - [%d],[%d] : ", row, col);
            scanf("%d", &arr[row][col]);
        }
    }
    

    for (row = 0; row < n; row++)
    {
        printf("\n");
        for (col = 0; col < m; col++)
        {
            printf("%d ", arr[row][col]);
        }
        
    }
    
    for (row = 0; row < n; row++)
    {
        for (col = 0; col < m; col++)
        {
            if (arr[row][col] % 2 != 0)
            {
                sum += arr[row][col];
            }
            
        }
        
    }
    
    printf("\nSum is: %d", sum);
    return 0;
}