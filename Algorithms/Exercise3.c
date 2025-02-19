#include <stdio.h>

void Calculate(int a, int *b){
    a += 10;
    *b = a + 20;
    printf("In function Calculate() a=%d\n", a);
    printf("In function Calculate() b=%d\n", *b);
}

int main(){
    int a, b;
    a = 20;
    b = 30;
    printf("Before function call a= %d\n", a);
    printf("Before function call b= %d\n", b);
    printf("------------------------------\n");
    Calculate(a, &b);
    printf("------------------------------\n");
    printf("After function call a = %d\n", a);
    printf("After function call b = %d\n", b);

    return 0;
}