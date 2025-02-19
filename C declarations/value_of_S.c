#include <stdio.h>
#include <math.h>
int main()
{
    double s = 0, j = 1, d, i;
    
    for (i = 1; i <= 7 ; i+=2)
    {
        d = (i/j);
        s += d;
        j = j * 2;
    }
    
    printf("Value of series is: %.2f", s);

    return 0;
}