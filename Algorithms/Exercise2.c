#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *arr1;
    double *arr2;
    int i;
    arr1 = (int*)malloc(sizeof(int) * 10);
    arr2 = (double*)malloc(sizeof(double) * 10);

    for (i = 0; i < 10; i++)
    {
        arr1[i] = i+1;
        arr2[i] = (i+1) / 2.0;
    }
    printf("Arrays contain: \n\n");
    for (i = 0; i < 10; i++)
    {
        printf("Arr1[%d] = %d, Arr2[%d] = %.2lf\n", i, arr1[i], i, arr2[i]);
    }
    
    free(arr1);
    free(arr2);
    return 0;
    

}