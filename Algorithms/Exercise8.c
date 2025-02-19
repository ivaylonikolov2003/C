#include<stdio.h>

int main(){

    int num;
    int sum = 0;
    int ones, tens, hundrets;

    printf("Enter a number: ");
    scanf("%d", &num);
    
    ones = num % 10;
    tens = (num / 10) % 10;
    hundrets = (num / 100) % 10;

    sum = ones + tens + hundrets;

    printf("The sum is: %d", sum); 

    return 0;
}