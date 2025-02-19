#include <stdio.h>
#include <stdlib.h>


int main(){
    double *arr, sum = 0.0;
    int num;

    printf("Enter number of symbols: ");
    scanf("%d", &num);

    arr = (double*)malloc(sizeof(double) * num);

    for (int i = 0; i < num; i++)
    {
        arr[i] = rand();
    }

    printf("The array contains: \n");
    for (int i = 0; i < num; i++)
    {
        printf("%.2f ", arr[i]);
    }
    
    
    for (int i = 0; i < num; i++)
    {
        if (arr[i] > 0)
        {
            sum += arr[i];
        }
    }
    printf("\nThe sum of positive values: %.2f\n", sum);
    
}