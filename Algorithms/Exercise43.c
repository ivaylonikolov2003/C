#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int arr[31][31];
    srand(time(NULL));

    for (int i = 0; i < 31; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            arr[i][j] = rand() % 100 + 1;
        }
        
    }
    
    int k = 30;
    int count = 0, sum = 0;

    for (int i = 0; i < 31; i++)
    {
        sum += arr[i][k--];
        count++;
    }
    
    int average = sum / count;
    int element = 0;

    for (int i = 0; i < 31; i++)
    {
        if (average == arr[i][k])
        {
            element = arr[i][k--];
        }
        
    }
    printf("\nSum: %d\n", sum);
    printf("Count: %d\n", count);
    printf("Average: %d\n", average);
    printf("Element is: %d", element);
    return 0;
}