#include <stdio.h>


int main(){
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n][n];
    printf("Enter elements for matrix %dx%d \n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           printf("element - [%d][%d]: ", i, j);
           scanf("%d", &arr[i][j]);
        }
    }

    printf("The matrix is: ");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        
    }
    
    int count = 0;
    int arr2[count];

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += arr[i][j];
        }
        arr2[count] = sum;
        count++;
        
    }
    
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (arr2[j] > arr2[j+1])
            {
                int temp = arr2[j];
                arr2[j] = arr2[j+1];
                arr2[j+1] = temp;
            }
            
        }
        
    }
    
    printf("\nThe second array: \n");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr2[i]);
    }
    

    return 0;
}