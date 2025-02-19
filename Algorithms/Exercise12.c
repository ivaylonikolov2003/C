#include <stdio.h>
#include <stdlib.h>
int const N = 5;
int main(){

    int arr[N], max, countOdds = 0, n, p = 0;
    double avgSum = 0, sum = 0;

    printf("Enter a numbers for an array: ");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter n: ");
    scanf("%d", &n);

    max = arr[0];
    for (int i = 0; i < N; i++)
    {   
        sum += arr[i];
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] % 2 != 0 && arr[i] != 0)
        {
            countOdds++;
        }
        if (arr[i] < 0)
        {
            if (arr[i] == n)
            {
                p = 1;
            }
            
        }
    }

    avgSum = sum / N;
    printf("Max = %d\n", max);
    printf("Avg sum = %.2f\n", avgSum);
    printf("Odds = %d\n", countOdds);
    if (p)
    {
        printf("YES!\n");
    }else{
        printf("NO!");
    }
    
    return 0;
}