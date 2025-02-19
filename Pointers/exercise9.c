#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Input total number of elements (1 to 100): ");
    scanf("%d", &n);

    int *numbers, i;

    numbers = (int*) malloc(n * sizeof(int));

    if (numbers == NULL)
    {
        printf("Memory is not allocated");
        exit(1);
    }
    
    for (i = 0; i < n; i++)
    {
        printf("Number %d: ", i + 1);
        scanf("%d", numbers + i);
    }
    
    for (i = 1; i < n; i++)
    {
        if (*numbers < *(numbers + i))
        {
            *numbers = *(numbers + i);
        }
    }
    
    printf("Largest element is: %d", *numbers);
}