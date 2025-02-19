#include <stdio.h>

int multiplicationOfNumbers(int num1, int num2)
{
    int result = num1 * num2;
    return result;
}

int main()
{
    
    int number1, number2;
    printf("Enter first number: ");
    scanf("%d", &number1);

    printf("Enter second number: ");
    scanf("%d", &number2);

    printf("Multiplication of numbers if: %d", multiplicationOfNumbers(number1, number2));

    return 0;
}