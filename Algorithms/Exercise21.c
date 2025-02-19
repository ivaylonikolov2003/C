#include <stdio.h>
int const N = 3;
int main(){
    int arr[N][N], count = 0;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("element - [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
        
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (arr[i][j] < arr[j][i])
            {
                count++;
            }
            
        }
        
    }
    
    printf("Count is: %d", count);

    return 0;
}