#include <stdio.h>
#define N 3
#define M 4

int MatrixInput()
{   
    int i, j;
    int arr[N][M];
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("Input n: ");
            scanf("%d", &arr[i][j]);
        }
        
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return arr[N][M];
}
int FindRowsCol()
{   
    int j, i;
    int arr[N][M];
    MatrixInput(arr[N][M]);
 
    for (i = 0; i < N; i++) 
    {
        for (j = 1; j < M; j++) 
        {
            if (arr[i][j] < arr[i][j - 1]) 
            {
                return 0;
            }
        }
    }
 
    for (j = 0; j < M; j++) 
    {
        for (i = 1; i < N; i++) 
        {
            if (arr[i][j] < arr[i - 1][j]) 
            {
                return 0;
            }
        }
    }
    return 1;
    
}

int main()
{
    int arr1[N][M];

    int flag = FindRowsCol(arr1[N][M]);

    if (flag != 0)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }

}