#include <stdio.h>
int const N = 6;
int main(){

    int arr[N], count;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < N-1; i++)
    {
        if ((arr[i] >= 0 && arr[i+1] < 0) || (arr[i] < 0 && arr[i+1] >= 0))
        {
            count++;
        }
        
    }
    
    printf("Count of numbers: %d", count);
    
}