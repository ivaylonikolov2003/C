#include <stdio.h>
#include <limits.h>

int gcd(int a, int b){
    if (a == 0)
    {
        return b;
    }else{
        return gcd(b % a, a);
    }
    
}

int main(){
    int n;

    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter positive numbers: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("The array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] % 2 == 0) && (max < arr[i]))
        {
            max = arr[i];
        }
        if ((arr[i] % 2 != 0) && (min > arr[i]))
        {
            min = arr[i];
        }
    }
    
    int number = gcd(max, min);

    printf("\nMax: %d\n", max);
    printf("Min: %d\n", min);
    printf("GCD: %d", number);
    

    return 0;
}