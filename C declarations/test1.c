#include <stdio.h>

int main()
{
    //Задача 2
    /*printf("The size of int is %d", sizeof(int));
    printf("\nThe size of long is %d", sizeof(long));
    printf("\nThe size of long long %d",sizeof(long long));
    printf("\nThe size of float %d", sizeof(float));
    printf("\nThe size of double %d", sizeof(double));
    printf("\nThe size of long double %d", sizeof(long double));*/
    
    //Задача 3
    /*printf("   *   *   *   * ");
   printf("\n*       *        *");
   printf("\n*                 *");
    printf("\n*                *");
    printf("\n *              *");
    printf("\n  *           *");
    printf("\n    *       *");
    printf("\n        *");*/

    //Задача 4
    /*int a, b, result;

    printf("Enter a first number: ");
    scanf("%d", &a);

    printf("Enter a second number: ");
    scanf("%d", &b);

    result = a * b;

    printf("Area of a rectangle is: %d", result);

    return 0;*/

    //Задача 5

    /*int a, b;
    
    printf("Enter a first num: ");
    scanf("%d", &a);

    printf("Enter a second num: ");
    scanf("%d", &b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("%d %d", a, b);

    return 0;*/

    //Задача 6

    int num, num1, num2, num3, num4, result;


    printf("Enter a number: ");
    scanf("%d", &num);

    num1 = num % 10;
    num2 = (num / 10) % 10;
    num3 = (num / 100) % 10;
    num4 = num / 1000;
    
    result = (num1 + num2 + num3 + num4);
    printf("%d", result);

    num1 *= 1000;
    num2 *= 100;
    num3 *= 10;
    num = num1 + num2 + num3 + num4;
    printf("\n%d", num);

}