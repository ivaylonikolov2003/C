#include <stdio.h>

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    for(int i = 1; i <= 100; i++)
    {
        if (i % number == 3)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}