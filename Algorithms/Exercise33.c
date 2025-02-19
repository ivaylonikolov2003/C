#include <stdio.h>

int main(){
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n][n];

    printf("Enter elements for matrix %dx%d", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("element - [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
        
    }
    printf("The matrix is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        
    }
    
    int sum = 0;
    int arr2[100];
    

    for (int i = 0; i < n; i++)
    {
        int min = arr[i][0];
        for (int j = 1; j < n; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
            
        }
        arr2[i] = min;        
    }
    for (int i = 0; i < n; i++)
    {
        sum += arr[i][i];   
    }
    arr2[n] = sum;
    printf("\nThe sum is: %d", sum);
    int negCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i][n - 1 - i] < 0) {
            negCount++;
        }
    }
    arr2[n + 1] = negCount;
    
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 1 - i; j++) {
            if (arr2[j] > arr2[j + 1]) {
                int temp = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = temp;
            }
        }
    }
    
    printf("\nThe array is: \n");
    for (int i = 0; i < n + 2; i++)
    {
        printf("%d ", arr2[i]);
    }
    
}