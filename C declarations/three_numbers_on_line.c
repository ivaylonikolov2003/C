#include <stdio.h>
#include <math.h>

int main()
{
    int i, n, j = 1;

    printf("Enter a number of lines: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= 3; j++)
        {
            printf("%d^%d = %.2f ",i,j, pow(i,j));
        }
        printf("\n");
    }
    return 0;
} 