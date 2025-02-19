#include <stdio.h>

int main()
{
    int p, q, b, i, j;

    printf("Enter a first integer: ");
    scanf("%d", &p);
    printf("Enter a second integer: ");
    scanf("%d", &q);

    for (i = 1, b = 1; i <= p; i++)
    {
        for(j = 1; j <= q; j++)
        {
            printf("%d ", b);
            b++;
        }
        printf("\n");
    }
    
    return 0;
}