#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 30
int main(){
    int A[SIZE][SIZE];
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            A[i][j] = rand() % 100 + 1;

        }
        
    }
    
    int largestElement = INT_MIN;

    for (int i = 0; i < SIZE; i++)
    {
        int element = A[i][i];
        
        if (element > largestElement)
        {
            largestElement = element;
        }
        
        if (i == 20)
        {
            break;
        }
    }

    printf("Element is: %d", largestElement);
    

}