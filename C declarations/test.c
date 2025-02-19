#include <stdio.h>

int main()
{
    char num;
    int num1;
    float num2;

    printf("Enter first num: ");
    scanf("%c", &num);

    printf("Enter second num: ");
    scanf("%d", &num1);

    printf("Enter third num: ");
    scanf("%f", &num2);

    printf("%c %d %d %.2f", num, num, num1, num2);

    return 0;

}