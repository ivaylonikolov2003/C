#include <stdio.h>
#include <stdlib.h>

int main(){
    int a;
    int b;

    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    a = a + b;//7
    b = a - b;//3
    a = a - b;//4

    printf("a = %d\n", a);
    printf("b = %d", b);

}