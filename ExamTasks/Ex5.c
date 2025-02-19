#include <stdio.h>
#include <stdlib.h>

void fill_array_from_file(int arr[], char *file_name);
void write_file(char *file_name);
void smaller_numbers_than_avg(int arr[]);
void min_number(int arr[]);
int main()
{
    int arr[1000];
    char *file_name;

    write_file("info.dat");
    fill_array_from_file(arr, "info.dat");

    for (int i = 0; i < 7; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("Smaller numbers than average:\n");
    smaller_numbers_than_avg(arr);

    min_number(arr);

    return 0;
}

void fill_array_from_file(int arr[], char *file_name)
{
    FILE *fp;
    int i = 0;
    int number;

    fp = fopen(file_name, "rb");

    if (fp == NULL)
    {
        printf("Open error");
        exit(1);
    }
    

    while (fread(&number, sizeof(int), 1, fp) == 1)
    {
        arr[i] = number;
        i++;
    }
    
    fclose(fp);
}

void write_file(char *file_name)
{
    FILE *fp;

    fp = fopen(file_name, "wb");

    for (int i = 1; i <= 7; i++)
    {
        fwrite(&i, sizeof(int), 1, fp);
    }
    
    fclose(fp);
}

void smaller_numbers_than_avg(int arr[])
{
    int sum = 0;
    double average = 0;

    for (int i = 0; i < 7; i++)
    {
        sum += arr[i];
    }
    
    average = sum / 7;

    for (int i = 0; i < 7; i++)
    {
        if (arr[i] < average)
        {
            printf("%d\n", arr[i]);
        }   
    }
}

void min_number(int arr[])
{
    int i;
    int min_num = -1;

    for (i = 0; i < 7; i += 2)
    {
        if (arr[i] % 10 == 7)
        {
            if (min_num == -1 || arr[i] < min_num)
            {
                min_num = arr[i];
            }
        }
        else
        {
            printf("there are no such numbers");
        }
    }

    printf("Min number is %d", min_num);
    
}