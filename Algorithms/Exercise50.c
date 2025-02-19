#include <stdio.h>

int main(){
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int A[n][n];
    int SP = 0, SO = 0, SD1 = 0, SD2 = 0, SN = 0;

    printf("Enter elements for matrix %dx%d:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
        
    }
    printf("The matrix is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                SD1 += A[i][j];
            }
            if ((i+j) == (n-1))
            {
                SD2 += A[i][j];
            }
            
            
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] > 0)
            {
                SP += A[i][j];
            }
            else if (A[i][j] < 0)
            {
                SO += A[i][j];
            }else if(A[i][j] == 0){
                SN += A[i][j];
            }
        }
        
    }
    
    
    printf("\nSP: %d\n", SP);
    printf("SO: %d\n", SO);
    printf("SD1: %d\n", SD1);
    printf("SD2: %d\n", SD2);
    printf("SN: %d\n", SN);
    return 0;
}