#include <stdio.h>
//Evklid
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

    printf("Enter n:");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    int max = arr[0];
    int min = arr[n - 1];
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] % 2 == 0) && (max < arr[i]))
        {
            max = arr[i];
        }else if ((arr[i] % 2 != 0) && (min > arr[i]))
        {
            min = arr[i];
        }
        
    }
    
    int GCD = gcd(max, min);
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    printf("GCD: %d\n", GCD);

    return 0;
}