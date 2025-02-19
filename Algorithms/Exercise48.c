#include <stdio.h>
#define MAX_SIZE 100
int main(){
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int A[n];
    int B[n];

    printf("Enter elements for first array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("Enter elements for second array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &B[i]);
    }

    printf("First array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", A[i]);
    }
    printf("\nSecond array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", B[i]);
    }
    
    int C[MAX_SIZE], count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                if (A[i] > B[i])
                {
                    C[count] = A[i];
                    count++;
                }else if (A[i] < B[i])
                {
                    C[count] = B[i];
                    count++;
                }
            }
        }
    }

    int sum = 0, number = 0;
    for (int i = 0; i < count; i++)
    {
        sum += C[i];
    }
    if (sum > 99 && sum <=999)
    {
        number = sum % 10;
    }
    
    printf("\nThird array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", C[i]);
    }
    printf("\nSum: %d\n", sum);
    printf("number: %d", number);
    return 0;
}