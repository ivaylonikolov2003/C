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

    printf("Enter elements for array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int g = arr[0];
    for (int i = 0; i < n; i++)
    {
        g = gcd(g, arr[i]);
    }
    
    printf("GCD: %d", g);
    return 0;
}