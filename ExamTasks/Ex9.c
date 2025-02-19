#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_NUMBERS 1000

void fill_array(int numbers[], int size);
double averageOddNumbers(int numbers[], int size, int a, int b);
int neg_numbers(int numbers[], int size);
int fill_array_neg(int numbers[], int size, int neg[]);
void remove_numbers(int numbers[], int *size);

int main()
{
    int a, b, new_len;
    int numbers[MAX_NUMBERS];
    double average;
    
    int size = sizeof(numbers) / sizeof(numbers[0]);
    fill_array(numbers, 5);

    printf("Original array: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", numbers[i]); 
    }
    printf("\n");

    remove_numbers(numbers, &size);

    printf("Array without numbers with 5:");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    
    /*new_len = neg_numbers(numbers, 5);
    int *negative = malloc(new_len * sizeof(int));
    fill_array_neg(numbers, 5, negative);
    for (int i = 0; i < new_len; i++)
    {
        printf("%d\n", negative[i]);
    }*/
    

    /*printf("Enter interval [a, b]: \n");
    printf("a= ");
    scanf("%d", &a);
    printf("b= ");
    scanf("%d", &b);

    average =  averageOddNumbers(numbers, 5, a, b);

    printf("\nAverage is: %.2f", average);*/
    
    return 0;
}

void fill_array(int numbers[], int size)
{
    int i;

    printf("Enter a numbers for array: \n");
    for (i = 0; i < size; i++)
    {
        printf("elemenet - %d : ", i+1);
        scanf("%d", &numbers[i]);
    }
    
}

double averageOddNumbers(int numbers[], int size, int a, int b)
{
    int sum = 0, i;
    int count = 0;
    double avg = 0;

    for (i = 0; i < size; i++)
    {
        if (numbers[i] >= a && numbers[i] <= b && numbers[i] % 2 != 0)
        {
            sum += numbers[i];
            count++;
        }
    }
    if (count == 0)
    {
        return 0.0;
    }

    avg = (double)sum / (double)count;

    return avg;
}

int neg_numbers(int numbers[], int size)
{
    int i;
    int count = 0;


    for (i = 0; i < size; i++)
    {
        if (numbers[i] < 0)
        {
            count++;
        }
    }

    return count;
}

int fill_array_neg(int numbers[], int size, int *neg)
{
    int j = 0;

    for (int i = 0; i < size; i++)
    {
        if (numbers[i] < 0)
        {
            neg[j] = i;
            j++;
        }
    }
}

void remove_numbers(int numbers[], int *size)
{
    int index = 0;

    for (int i = 0; i < *size; i++)
    {
        if (numbers[i] % 10 != 5)
        {
            numbers[index] = numbers[i];
            index++;
        }
    }
    
    *size = index;
}