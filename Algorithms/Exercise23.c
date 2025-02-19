#include <stdio.h>

float stepen(float x, int n){

    if (n == 0)
    {
        return 1;
    }else{
        if (n > 0)
        {
            return (x * stepen(x, n - 1));
        }else{
            return (1 / stepen(x, -n));
        }
        
    }
    
}

int main(){
    int n;
    float x;

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter x: ");
    scanf("%f", &x);

    printf("%.2f^%d = %.2f", x, n, stepen(x, n));
}