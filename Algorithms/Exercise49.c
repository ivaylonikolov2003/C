#include <stdio.h>
#include <limits.h>
#define MAX_SIZE 100

int main(){
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n][n];

    printf("Enter elements for matrix %dx%d:\n", n , n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("The matrix is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
    }
    int sum = 0, negCount = 0;
    int B[MAX_SIZE];
    for (int i = 0; i < n; i++)
    {
        int min = arr[i][0];
        for (int j = 1; j < n; j++)
        {
            if (min > arr[i][j])
            {
                min = arr[i][j];
            }
        }
        B[i] = min;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                sum += arr[i][j];
            }
            if ((i+j) == (n - 1))
            {
                if (arr[i][j] < 0)
                {
                    negCount++;
                }   
            }
        }
    }
    
    B[n] = sum;
    B[n + 1] = negCount;
    printf("\nB:\n");
    for (int i = 0; i < n + 2; i++)
    {
        printf("%d ", B[i]);
    }
    
    printf("\nSum: %d\n", sum);
    printf("Neg count: %d", negCount);  

    return 0;
}