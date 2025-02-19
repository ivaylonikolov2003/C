#include <stdio.h>
int const N = 5;
int main(){

    int arr[N], sum = 0, produced = 1;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < N - 1; i++)
    {   
        for (int j = 0; j < N - 1; j++)
        {
            sum = arr[i] + arr[j + 1];
            if (sum <= 120)
            {
                produced = produced * arr[i] * arr[j + 1];
            }
        }
    }

    printf("Proizvedenieto e %d", produced);    
    return 0;
}