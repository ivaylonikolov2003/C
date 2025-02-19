#include <stdio.h>

int main()
{
    int num, i;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num > 0)
    {
        printf("Sequence:\n");
        for (i = 1; i < num; i++)
        {
            printf("%d, ", i);
        }
        printf("%d\n", i);
        
    }
    return 0;
}