#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 4;
    int *ages, i;

    ages = (int*) malloc(n * sizeof(int));

    if (ages == NULL)
    {
        printf("Memory cannot be allocated!");
        return 0;
    }

    printf("Enter input values:\n");
    for (i = 0; i < n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", ages + i);
    }
    printf("Element in the array are: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(ages + i));
    }
    
    n = 6;

    ages = realloc(ages, n * sizeof(int));
    ages[4] = 32;
    ages[5] = 59;

    printf("\nNew elements in the array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(ages + i));
    }

    free(ages);    

    return 0;
}