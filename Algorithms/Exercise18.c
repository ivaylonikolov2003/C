#include <stdio.h>
int const N = 2;
int main(){

    int arr[N][N];

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
            if ((j > i) && (arr[i][j] % 2 != 0))
            {
                arr[i][j] = arr[i][j] + 1;
                arr[i][i]++;
            }if ((j < i) && (arr[i][j] % 2 == 0))
            {
                arr[i][j] = arr[i][j] - 1;
                arr[i][i]++;
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
    

}