#include <stdio.h>

int main()
{
    int p, q, r, s;
    printf("Enter first positive number: ");
    scanf("%d", &q);
    printf("Enter second positive number: ");
    scanf("%d", &r);
    printf("Enter third positive number: ");
    scanf("%d", &s);
    printf("Enter even number: ");
    scanf("%d", &p);

    int sum1 = r + s;
    int sum2 = p + q;

    if ((q > r) && (s > p) && (sum1 > sum2)) 
    {
        printf("Correct Values");
    }
    else
    {
        printf("Wrong Values");
    }
    
    return 0;
}