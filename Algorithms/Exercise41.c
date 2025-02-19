#include <stdio.h>
#define MAX_SIZE 100
int main(){
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int A[n], B[n];

    printf("Enter first array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("Enter second array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &B[i]);
    }
    
    int count = 0;
    int C[MAX_SIZE];
    for (int i = 0; i < n; i++)
    {
        if (A[i] > 0)
        {
            C[count] = A[i];
            count++;
        }
        
        
    }
    for (int i = 0; i < n; i++)
    {
        if (B[i] % 2 == 0)
        {
            C[count] = B[i];
            count++;
        }
        
    }
    
    for (int i = 0; i < count; ++i) 
    {
        for (int j = i + 1; j < count; ++j) 
        {
            if (C[i] < C[j]) 
            {
                int temp = C[i];
                C[i] = C[j];
                C[j] = temp;
            }
        }
    }

    printf("C array: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", C[i]);
    }

    return 0;
}