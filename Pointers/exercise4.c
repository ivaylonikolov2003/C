#include <stdio.h>

int AddTwoNumbers(int *n, int *m)
{
    int sum;
    sum = *n + *m;
    return sum;
}

int main()
{
    int m, n, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &m);
    printf("Enter second number: ");
    scanf("%d", &n);

    sum = AddTwoNumbers(&m, &n);

    printf("Sum is: %d", sum);

    return 0;
}