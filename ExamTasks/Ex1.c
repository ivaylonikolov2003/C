#include <stdio.h>

void input_array(int arr[]);
void average_even_sum(int arr[]);
void find_min_num(int arr[]);
int delete_positive_num(int arr[]);

int main()
{
    int arr[10];

    input_array(arr);

    for (int i = 1; i <= 10; i++)
    {
        printf("%d ", arr[i]);
    }
    
    average_even_sum(arr);
    find_min_num(arr);
    printf("\nDeleted elements from array are: %d", delete_positive_num(arr));

    return 0;
}

void input_array(int arr[])
{
    int i;
    printf("Enter a numbers for array: \n");

    for (i = 1; i <= 10; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }
    
}

void average_even_sum(int arr[])
{
    int sum = 0, i, count = 0;
    double average_sum = 0;

    for (i = 1; i <= 10; i++)
    {
        if (arr[i] > 0 && arr[i] % 6 == 0)
        {
            sum += arr[i];
            count++;
        }
    }

    printf("\nSum is %d\n", sum);
    printf("Count is %d\n", count);
    average_sum = (double)sum / (double)count; 
    printf("Average sum is: %.2lf", average_sum);
}

void find_min_num(int arr[])
{
    int min_num;
    min_num = 999;
    
    for (int i = 1; i <= 5; i++)
    {
        if (arr[i] > 0 && arr[i] < min_num)
        {
            min_num = arr[i];
        }
    }
    
    printf("\nMinimum number is: %d", min_num);
}

int delete_positive_num(int arr[])
{
    int i, count = 0, j, size = 10;

    for (i = 0; i < size; i++)
    {
        if (arr[i] > 0 && arr[i] % 10 == 7) 
        {
            count++;

            for (j = i; j < size - 1; j++) 
            {
                arr[j] = arr[j + 1];
            }
            
            size--;
            i--;
        }
    }
    
    return count;
}
