#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Car
{
    char brand[20];
    char model[20];
    int year;
    double price;
}car;

void fill_struct(car *cars, int size, FILE *fp);

int main()
{
    car *cars;
    FILE *fp;

    fp = fopen("Car.txt", "w");

    if (fp == NULL)
    {
        printf("Error");
        exit(1);
    }

    fill_struct(cars, 3, fp);

    fclose(fp);


    return 0;
}

void fill_struct(car *cars, int size, FILE *fp)
{
    car cars1;

    printf("Enter car brand: ");
    scanf("%s", cars1.brand);

    printf("Enter car model: ");
    scanf("%s", cars1.model);

    printf("Enter car year: ");
    scanf("%d", &cars1.year);

    printf("Enter car price: ");
    scanf("%lf", &cars1.price);

    fprintf(fp, "%d; %s; %s; %d; %.2f", strlen(cars1.brand), cars1.brand, cars1.model, cars1.year, cars1.price);

    cars = (car*)malloc(++size * sizeof(car));

    cars[size - 1] = cars1;
}

car *return_bigger_car_price(car *old_cars, int old_arr_len, double price, int *new_len)
{   
    //намиране на броя коли с по голяма цена от зададената
    int count = 0;
    for (int i = 0; i < old_arr_len; i++)
    {
        if (old_cars[i].price > price)
        {
            count++;
        }
    }

    //създаване на нов динамичен масив
    car *new_car = malloc(sizeof(car) * count);
    count = 0;
    //попълване на масива според условието
    for (int i = 0; i < old_arr_len; i++)
    {
        if (old_cars[i].price > price)
        {
            new_car[count] = old_cars[i];
            count++;
        }
    }

    *new_len = count;
    return new_car;
}

void read_from_file()
{
    int len_str;
    char car_name[10], car_model[10];
    int year;
    double price;

    FILE *fp;

    fp = fopen("Auto.bin", "rb");

    if (fp == NULL)
    {
        printf("Error");
        exit(2);
    }

    while (fp != EOF)
    {   
        fread(&len_str, sizeof(int), 1, fp);
        fread(car_name, len_str, 1, fp);
        fread(car_model, sizeof(car_model), 1, fp);

        car_name[len_str] = '\0';
        car_model[9] = '\0';

        fread(&year, sizeof(int), 1, fp);
        fread(&price, sizeof(double), 1, fp);
    }

    fclose(fp);
    
    fp = fopen("Text.txt", "w");

    if (fp == NULL)
    {
        printf("Error");
        exit(3);
    }
    
    fprintf(fp, "Car name: %s\n", car_name);
    fprintf(fp, "Car model: %s\n", car_model);
    fprintf(fp, "Car year: %d\n", year);
    fprintf(fp, "Car price: %lf\n", price);
    
    fclose(fp);
}