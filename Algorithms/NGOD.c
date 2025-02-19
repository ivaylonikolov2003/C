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

int main(){
    int num1, num2;
    int result = 0;
    printf("Enter num 1: ");
    scanf("%d", &num1);

    printf("Enter num 2: ");
    scanf("%d", &num2);

    result = GreatCommDiv(num1, num2);

    printf("Result is: %d", result);

}