#include <stdio.h>

int main()
{
    int n, i;
    int *ptr1 = &n;

    printf("Enter n: ");
    scanf("%d", &n);

    int arr[*ptr1];

    for (i = 0; i < *ptr1; i++)
    {
        printf("Enter element - %d : ", i);
        scanf("%d", &arr[i]);
    }
    
    for (i = 0; i < *ptr1; i++)
    {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}