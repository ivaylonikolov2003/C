#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Clinic
{
    char owner_name[31];
    char chip_number[8];
    double price;
}clinic;

clinic input_pets(void);
void print_pets_by_price(clinic pets[], unsigned size, double price);
void read_print_pets(double price);

int main()
{
    clinic pets[31];
    int size = 3;

    for (int i = 0; i < size; ++i)
    {
        pets[i] = input_pets();
    }
    
    writeToBin("Animal.bin", pets, 3);
    print_pets_by_price(pets, 30, 45.50);

    read_print_pets(20.0);

    return 0;
}


clinic input_pets(void)
{
    clinic pet1;

    FILE *fp;

    printf("Enter owner name: ");
    fgets(pet1.owner_name, 31, stdin);
    pet1.owner_name[strlen(pet1.owner_name) - 1] = '\0';
    fflush(stdin);

    printf("Enter chip number: ");
    fgets(pet1.chip_number, 8, stdin);
    fflush(stdin);


    printf("Enter price: ");
    scanf("%lf", &pet1.price);
    fflush(stdin);

    fp = fopen("Animal.txt", "a");

    if (fp == NULL)
    {
        printf("Open error");
        exit(1);
    }
    
    fprintf(fp, "%s,%.2lf\n", pet1.owner_name, pet1.price);

    fclose(fp);

    return pet1;
}


void print_pets_by_price(clinic pets[], unsigned size, double price)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (pets[i].price == price)
        {
            count++;
        }
    }
    
    if (count == 0)
    {
        printf("No such data!");
    }

    for (int i = 0; i < size; i++)
    {
        if (pets[i].price == price)
        {
            printf("%s - %s\n", pets[i].owner_name, pets[i].chip_number);
        }
    }

}

void read_print_pets(double price)
{
    FILE *fp;

    int len_str;
    char owner_name[31], chip[8];
    double pet_price;

    fp = fopen("Animal.bin", "rb");

    if (fp == NULL)
    {
        printf("Bin open error");
        exit(3);
    }
    
    len_str = strlen(owner_name);

    while (!feof(fp))
    {
        fread(&len_str, sizeof(int), 1, fp);
        fread(owner_name, len_str, 1, fp);
        owner_name[len_str] = '\0';
        fread(chip, 7, 1, fp);
        chip[7] = '\0';
        fread(&pet_price, sizeof(double), 1, fp);

        if (pet_price >= price)
        {
            printf("Bin owner name: %s\n", owner_name);
            printf("Bin Chip: %s\n", chip);
            printf("Bin price: %.2lf\n", pet_price);
            break;
        }
        
    }
    
    fclose(fp);

}