#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    double S1 = 0, S2 = 0;
    int count = 0, Sum = 0;

    printf("Enter n: ");
    scanf("%d", &n);
    if (n % 2 == 0)
    {
        printf("Enter an odd number");
        return 1;
    }
    
    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    int max = A[0];
    int min = A[0];
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
        if (A[i] < min)
        {
            min = A[i];
        }
    }
    int middleElement = A[n / 2];
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            Sum += A[i];
            count++;
        }
        
    }
    S1 = (max + min + middleElement) / 3;
    printf("sum: %d", Sum);
    printf("\nCount: %d", count);
    S2 = Sum / count;
    printf("\nMax element is: %d", max);
    printf("\nMin: %d", min);
    printf("\nMid point is: %d", middleElement);
    printf("\nS1: %.3f", S1);
    printf("\nS2: %.3f", S2);
    
    return 0;
}