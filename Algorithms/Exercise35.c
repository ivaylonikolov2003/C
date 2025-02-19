#include <stdio.h>

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n][n];
    printf("Enter elements for matrix %dx%d ", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("element - [%d][%d]: ", i, j);
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
    
    int polCount = 0, negCount = 0, nulCount = 0, diagCount= 0, secCount = 0;
    int polSum = 0, negSum = 0, diagSum = 0, secondDiagSum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] > 0)
            {
                polSum += arr[i][j];
                polCount++;
            }else if (arr[i][j] < 0)
            {
                negSum += arr[i][j];
                negCount++;
            }else{
                nulCount++;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                diagSum += arr[i][j];
                diagCount++;
            }else if ((i + j) == (n - 1))
            {
                secondDiagSum += arr[i][j];
                secCount++;
            }
        }
    }
    
    double avgPos = polSum / polCount;
    double avgNeg = negSum / negCount;
    double avgPrimary = diagSum / diagCount;
    double avgSecondary = secondDiagSum / secCount;

    printf("\nPol sum: %d\n", polSum);
    printf("Neg sum: %d\n", negSum);
    printf("Diag sum: %d\n", diagSum);
    printf("Secondary sum: %d\n", secondDiagSum);
    printf("Pol count: %d\n", polCount);
    printf("Negative count: %d\n", negCount);
    printf("Diag count: %d\n", diagCount);
    printf("Second count: %d\n", secCount);
    printf("Avg positive: %.2f\n", avgPos);
    printf("Avg negative: %.2f\n", avgNeg);
    printf("Avg primary: %.2f\n", avgPrimary);
    printf("Avg secondary: %.2f\n", avgSecondary);

    return 0;
}