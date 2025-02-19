#include <stdio.h>

int main()
{
    double salary;
    double *salary1;
    printf("Enter a salary: ");
    scanf("%lf", &salary);

    salary1 = &salary;

    printf("Value of the salary is: %.2f", *salary1);

    salary *= 2;

    printf("\nThe new salary is: %.2f", salary);

    return 0;

}