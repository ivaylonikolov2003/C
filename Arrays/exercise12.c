#include <stdio.h>

int main()
{
    int n, i, j = 0, k = 0;
    int even[100], odd[100];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr1[n];

    for (i = 0; i < n; i++)
    {
        printf("element - %d : ",i);
        scanf("%d", &arr1[i]);
    }
    
    for (i = 0; i < n; i++)
    {
        if (arr1[i] % 2 == 0)
        {
            even[j] = arr1[i];
            j++;
        }
        else
        {
            odd[k] = arr1[i];
            k++;
        }
        
    }
    
    printf("Even elements are: \n");
    for (i = 0; i < j; i++)
    {
        printf("%d ", even[i]);
    }

    printf("\nOdd elements are: \n");
    for (i = 0; i < k; i++)
    {
        printf("%d ", odd[i]);
    }
    

    return 0;
}