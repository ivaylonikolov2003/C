#include <stdio.h>
int gcd(int m, int n){

    while (n != 0)
    {
        int rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}


int main(){

    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int g = arr[0];
    for (int i = 0; i < n; i++)
    {
        g = gcd(g, arr[i]);
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
    printf("GCD: %d\n", g);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    

    return 0;
}