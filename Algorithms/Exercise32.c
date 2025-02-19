#include <stdio.h>

int main(){
    int n;
    
    printf("Enter n: ");
    scanf("%d", &n);
    int arr1[n], arr2[n];

    printf("Enter elements for first arr: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter elements for second arr: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr1[j] > arr1[j+1])
            {
                int temp = arr1[j];
                arr1[j] = arr1[j+1];
                arr1[j+1] = temp;
            }
            
        }
        
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr2[j] > arr2[j+1])
            {
                int temp = arr2[j];
                arr2[j] = arr2[j+1];
                arr2[j+1] = temp;
            }
        }
    }
    printf("\nFirst array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\nSecond array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr2[i]);
    }
    int count = 0, sum = 0, tens;
    int arr3[count];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                if (arr1[i] > arr2[j])
                {
                    arr3[count] = arr1[i];
                    count++;
                }else{
                    arr3[count] = arr2[j];
                    count++;
                }
                
            }
            
        }
        
    }
    
    for (int i = 0; i < count; i++)
    {
        sum += arr3[i];
    }
    if (sum >= 100 && sum <= 999)
    {
        tens = sum % 10;
    }else{
        tens = 0;
    }
    
    printf("\nThird array: \n");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr3[i]);
    }
    
    printf("\nSum: %d", sum);
    printf("\nTens: %d", tens);


    return 0;
}