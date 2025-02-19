#include <stdio.h>
int const N = 5;


int main(){

    int arr[N], count = 0, j;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < N - 1; i++)
    {
        if (arr[i] == arr[i+1])
        {
            j = i;
            while (arr[i] == arr[i+1])
            {
                j++;
            }
            count++;
            i = j;
        }
        
    }
    
    printf("Count of equals elements are: %d", count);

    return 0;
}