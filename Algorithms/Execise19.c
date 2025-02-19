#include <stdio.h>
int const N = 3;
int main(){
    int arr[N][N], sum = 0;


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("element - [%d],[%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if ((i + j) == (N - 1))
            {
                sum += arr[i][j];
            }
            
        }
        
    }
    for (int i = 0; i < N; i++)
    {
        printf("\n");
        for (int j = 0; j < N; j++)
        {
            printf("%d ", arr[i][j]);
        }
        
    }
    

    printf("\nThe sum is: %d", sum);

    return 0;
}