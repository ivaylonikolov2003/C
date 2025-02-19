#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 1000

void fill_array(double nums[], int size);
void biggest_negative_num(double nums[], int size);
void avg_odd_nums(double nums[], int size);
double *negative_array(double nums[], int size);
void find_min_num(double nums[], int size);

int main()
{
    double numbers[MAX_NUMBERS];
    int size;

    printf("How numbers want to input: ");
    scanf("%d", &size);

    fill_array(numbers, size);

    printf("Elements in the array are:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%.2f\n", numbers[i]);
    }

    //biggest_negative_num(numbers, size);
    //avg_odd_nums(numbers, size);
    
    /*double *result = negative_array(numbers, size);

    printf("Negative numbers smaller than half sum is:");
    for (int i = 0; i < size; i++)
    {
        if (result[i] < 0)
        {
            printf("%.2f ", result[i]);
        }
        
    }
    
    free(result);*/

    find_min_num(numbers, size);
    return 0;
}


void fill_array(double nums[], int size)
{
    printf("Enter numbers for array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("element - %d: ", i+1);
        scanf("%lf", &nums[i]);
    }
    
}

void biggest_negative_num(double nums[], int size)
{
    double max_negative_num = -999;
    int index = 0;

    for (int i = 0; i < size; i++)
    {
        if (nums[i] > max_negative_num)
        {
            max_negative_num = nums[i];
            index = i;
            index++;
        }
    }
    
    printf("Max negative num: %.2f\n", max_negative_num);
    printf("Index is: %d", index);

}

void avg_odd_nums(double nums[], int size)
{
    double sum = 0;
    double average = 0;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (i % 2 != 0)
        {
            sum += nums[i];
            count++;
        }
    }

    average = sum / (double)count;

    printf("Average is %.2f", average);
}


double *negative_array(double nums[], int size)
{
    double sum = 0, half_sum = 0;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        sum += nums[i];
    }
    
    half_sum = sum / 2.0;

    double *result = (double*)malloc(size * sizeof(double));

    for (int i = 0; i < size; i++)
    {
        if (nums[i] < half_sum)
        {
            result[count] = (double)nums[i];
            count++;
        }
    }
    
    return result;
}

void find_min_num(double nums[], int size)
{
    double min_num = 999;

    for (int i = 0; i < size / 2; i++)
    {
        if (nums[i] < min_num)
        {
            min_num = nums[i];
        }
    }
    
    printf("Minimum number is: %.2f", min_num);

}