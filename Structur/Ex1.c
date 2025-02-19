#include <stdio.h>

typedef struct Complex
{
    double real;
    double imagine;
} complex;


int main()
{

    complex num1 = {.real = 10.5, .imagine = 12.5};
    complex num2 = {.real = 3.5, .imagine = 4.5};
    complex num3 = {.real = 4.5, .imagine = 6.5};

    complex subtraction;

    subtraction.real = num1.real - num2.real - num3.real;
    subtraction.imagine = num1.imagine - num2.imagine - num3.imagine;

    printf("Result is %.2lf + %.2lfi", subtraction.real, subtraction.imagine);
    

    return 0;
}