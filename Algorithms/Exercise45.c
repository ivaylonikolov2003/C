#include <stdio.h>


int main(){
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n][n];

    printf("Enter elements for matrix from 1 to 100 %dx%d:\n", n , n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
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

    int k = n - 1;
    int count = 0, sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i][k--];
        count++;
    }
    int average = sum / count;
    int element = 0;
    for (int i = 0; i < count; i++)
    {
        if (average == arr[i][k])
        {
            element = arr[i][k--];
        }
    }
    
    printf("\nSum: %d\n", sum);
    printf("Count: %d\n", count);
    printf("Average: %d\n", average);
    printf("Element is: %d", element);

    return 0;
}