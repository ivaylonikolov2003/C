#include <stdio.h>
int const N = 5;


int calculateSum(int arr[], int n) {
    // Базов случай: ако масивът е празен, сумата е 0
    if (n == 0) {
        return 0;
    } else {
        // Рекурсивно извикване за останалата част от масива
        return arr[n - 1] + calculateSum(arr, n - 1);
    }
}


int main(){
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    int sum = calculateSum(arr, N);
    printf("Sum is: %d", sum);
}