#include <stdio.h>

int main()
{
    int n, i, sum = 0;

    printf("Enter a value of the array: ");
    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++)
    {
        printf("Enter a number between [-5000 - 5000]: ", i);
        scanf("%d", &arr[i]);
    }
    
    for (i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    
    printf("Sum is %d", sum);

    return 0;
}