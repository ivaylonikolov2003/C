#include <stdio.h>

int main()
{
    char operator;
    double num1, num2;
    printf("Choose an operator ('+', '-', '*', '/'): ");
    scanf("%c", &operator);


    printf("Enter a first number: ");
    scanf("%lf", &num1);

    printf("Enter a second number: ");
    scanf("%lf", &num2);

    double result;

    switch (operator)
    {
    case '+':
        result = num1 + num2;
        printf("%.2f", result);
        break;

    case '-':
        result = num1 - num2;
        printf("%.2f", result);
        break;
    case '*':
        result = num1 * num2;
        printf("%.2f", result);
        break;
    case '/':
        result = num1 / num2;
        printf("%.2f", result);
        break;
    
    default:
        break;
    }


}