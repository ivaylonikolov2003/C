#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Car
{
    char brand[20];
    char model[6];
    double engine_volume;
    double price;
    char registration;
}car;

void write_to_binary(car *cars, int count);
void write_to_text(car *cars, int count);
void add_new_car(car *cars, int count);
void read_from_binary();
void read_from_text();


int main()
{   
    car cars[100];
    int count = 0;
    int choice;

    do
    {
        printf("Menu:\n");
        printf("1. Add a new entry:\n");
        printf("2. Save the data to a binary file\n");
        printf("3. Save the data to a text file\n");
        printf("4. Output the data from a binary file\n");
        printf("5. Output the data from a text file\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_new_car(cars, count);
            count++;
            break;
        case 2:
            write_to_binary(cars, count);
            break;
        case 3:
            write_to_text(cars, count);
            break;
        case 4:
            read_from_binary();
            break;
        case 5:
            read_from_text();
            break;
        case 6:
            printf("Bye!");
            break;
        default:
            printf("Invalid option. Please, try again.");
            break;
        }

        printf("\n");
    } while (choice != 6);

    return 0;
}

void write_to_binary(car *cars, int count)
{
    FILE *fp;

    fp = fopen("Auto.bin", "wb");

    if (fp == NULL)
    {
        printf("Error opening");
        exit(1);
    }
    
    fwrite(cars, sizeof(car), count, fp);
    fclose(fp);
    printf("Succesfully data recorded!\n");
}

void write_to_text(car *cars, int count)
{
    FILE *fp;
    fp = fopen("Cars.txt", "w");

    if (fp == NULL)
    {
        printf("Open error");
        exit(2);
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%s %s %.2f %.2f %c\n", cars[i].brand, cars[i].model, cars[i].engine_volume, cars[i].price, cars[i].registration);
    }
    
    fclose(fp);

    printf("Succesfully data recorded!");
}

void add_new_car(car *cars, int count)
{
    printf("Enter car brand: ");
    scanf("%20s", cars[count].brand);

    printf("Enter car model: ");
    scanf("%6s", cars[count].model);

    printf("Enter engine volume: ");
    scanf("%lf", &cars[count].engine_volume);

    printf("Enter price: ");
    scanf("%lf", &cars[count].price);

    printf("Enter registration number (Y or N): ");
    scanf(" %c", &cars[count].registration);

    printf("New record succesfully recorded!\n");
}

void read_from_binary()
{

    FILE *fp = fopen("Auto.bin", "rb");

    if (fp == NULL)
    {
        printf("Open error");
        exit(3);
    }
    
    car car1;
    printf("Data from binary file:\n");
    while (fread(&car1, sizeof(car), 1, fp))
    {
        printf("Bin brand: %s\n", car1.brand);
        printf("Bin model: %s\n", car1.model);
        printf("Bin volume engine: %.2f\n", car1.engine_volume);
        printf("Bin price: %.2f\n", car1.price);
        printf("Bin registration: %c\n", car1.registration);
    }

    fclose(fp);
    
}

void read_from_text()
{
    FILE *fp = fopen("Cars.txt", "r");

    if (fp == NULL)
    {
        printf("Open error");
        exit(3);
    }

    char brand[20];
    char model[6];
    double engine_volume;
    double price;
    char registration;

    printf("Data from text file:\n");
    while (fscanf(fp, "%19s %5s %lf %lf %c\n", brand, model, &engine_volume, &price, &registration) == 5)
    {
        printf("Text brand: %s\n", brand);
        printf("Text model: %s\n", model);
        printf("Text volume engine: %.2f\n", engine_volume);
        printf("Text price: %.2f\n", price);
        printf("Text registration: %c\n", registration);
    }

    fclose(fp);
    
}