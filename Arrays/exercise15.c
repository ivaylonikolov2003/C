#include <stdio.h>

int main()
{
    int n, i, j = 0, max_element, second_max;

    printf("Enter a number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }
    
    max_element = 0;
    for (i = 0; i < n; i++)
    {
        if (max_element < arr[i])
        {
            max_element = arr[i];
            j = i;
        }
        
    }
    
    second_max = 0;
    for (i = 0; i < n; i++)
    {
        if (i == j)
        {
            i++;
            i--;
        }
        else
        {
            if (second_max < arr[i])
            {
                second_max = arr[i];
            }
            
        }
    }
    

    printf("\nSecond largest element in the array is: %d", second_max);

}