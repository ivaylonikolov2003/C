#include <stdio.h>

int main()
{
    int arr[10];

    for (int i = 0; i < 10 ; i++)
    {
        printf("element - %d: ", i);
        scanf("%d", &arr[i]);
    }
    
    printf("\nElements in the array are: ");
    for (int j = 0; j < 10; j++)
    {
        printf("%d ", arr[j]);
    }
    

}