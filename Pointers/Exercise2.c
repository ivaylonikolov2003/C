#include <stdio.h>

int main()
{
    long i, n, *largest;

    printf("Enter a number of elements in the array: ");
    scanf("%ld", &n);

    long arr[n]; 
    for (i = 0; i < n; i++)
    {
        printf("element - %d : ", i);
        scanf("%ld", &arr[n]);
    }

     largest = arr;
    *largest = *arr;

    for (i = 1; i < n; i++)
    {
        if (*largest < *(arr + i))
        {
            *largest = *(arr + i);
        }
        
    }
    
    printf("Largest value is: %ld", *largest);

    return 0;
}