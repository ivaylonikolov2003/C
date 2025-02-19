#include <stdio.h>

int main()
{
    int n, i, j, frequency = -1, count = 1;

    printf("Enter a number of values in the array: ");
    scanf("%d", &n);

    int arr[n];
    int fr[n];

    for (i = 0; i < n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }


    for (i = 0; i < n; i++)
    {
        count = 1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                fr[j] = frequency;
            }
        }
        
        if (fr[i] != frequency)
        {
            fr[i] = count;
        }
        
    }
    
    printf("Frequency of all elements of an array:\n");
    for (i = 0; i < n; i++)
    {
        if (arr[i] != frequency)
        {
            printf("%d occurs %d\n", arr[i], fr[i]);
        }
        
    }
    
    return 0;
}