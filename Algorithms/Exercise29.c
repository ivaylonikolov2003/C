#include <stdio.h>

int main(){

    int evenCount = 0, n;

    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; i < n - i - 1; i++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0 && (arr[i] > 100 && arr[i] < 10000))
        {
            evenCount++;
        }
    }
    
    printf("Even count: %d", evenCount);
}