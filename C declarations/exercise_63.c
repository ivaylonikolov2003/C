#include <stdio.h>
#include <math.h>

int main()
{
    int n, m, result = 0, i;
    printf("Enter a number: ");
    scanf("%d", &n);

    if(n < 100 && n > 0)
    {
        m = 1;
        for (i = 1; m <= n; i++)
        {
            result += pow(m, 4);
            m += i;
        }
        
    }
    else
    {
        printf("Invalid value!");
    }

    printf("Sum of the series is %d", result);

    return 0;
}