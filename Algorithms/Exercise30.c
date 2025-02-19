#include <stdio.h>

int GreatCommDiv(int m ,int n){
    int r;
    while (n != 0)
    {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}
int GCD(int n, int a[n]){
    if(n==1) return a[0];
    if(n==2) return GreatCommDiv(a[0], a[1]);
    int h = n / 2;
    return GreatCommDiv(GCD(h, &a[0]), GCD(n - h, &a[h]));
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

    int gcd = GCD(n, arr);
    printf("GCD: %d\n", gcd);

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
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
}