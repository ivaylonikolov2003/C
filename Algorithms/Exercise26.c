#include <stdio.h>

int test(int num, int digit){
    if (num < 0)
    {
        return 1;
    }
    if (num % 10 == digit)
    {
        return digit;
    }
    return test(num /10, digit);
}

int main(){
    int number, digit;

    printf("Enter number: ");
    scanf("%d", &number);
    printf("Enter digit: ");
    scanf("%d", &digit);

    if (test(number, digit) >= 0)
    {
        printf("YES! %d", digit);
    }else{
        printf("NO!");
    }
    
    return 0;
}