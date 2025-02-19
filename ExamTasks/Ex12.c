#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Phone
{
    char id[12];
    char model[20];
    double price;
    int quantity;
}phone;



int main()
{

    return 0;
}

void add_new_phone(phone *phones, int size, FILE *fp)
{
    phone phone1;

    printf("Enter phone id: ");
    scanf("%12s", phone1.id);

    printf("Enter phone model: ");
    scanf("%20s", phone1.model);

    printf("Enter phone price: ");
    scanf("%lf", phone1.price);

    printf("Enter quantity: ");
    scanf("%d", phone1.quantity);

    fprintf(fp, "%d | %s | %s | %lf | %d", strlen(phone1.model), phone1.id, phone1.model, phone1.price, phone1.quantity);

    size++;
    phones = realloc(phones, sizeof(phone) * size);
    if (!phones)
    {
        exit(1);
    }
    phones[size - 1] = phone1;
}

void print_phone(phone *phones, int count_element)
{
    double avg_price = 0;

    for (int i = 0; i < count_element; i++)
    {
        avg_price += phones[i].price;
    }

    avg_price /= count_element;

    for (int i = 0; i < count_element; i++)
    {
        if (phones[i].price > avg_price)
        {
            printf("Phone name: %s", phones[i].model);
            printf("Phone price: %.2lf", phones[i].price);
        }
        
    }

}

void read_from_bin_file(char id[12])
{
    int len_str, quant;
    char phone_model[20], phone_id[12];
    double price;

    FILE *fp;

    fp = fopen("Phone.bin", "rb");

    while (!feof(fp))
    {
        fread(&len_str, sizeof(int), 1, fp);
        fread(phone_id, 11, 1, fp);
        fread(phone_model, len_str, 1, fp);

        phone_id[11] = '\0';
        phone_model[len_str] = '\0';

        fread(&price, sizeof(double), 1, fp);

        if (strcmp(phone_id, id) == 0)
        {
            printf("Bin phone name: %s", phone_model);
            printf("Bin id: %s", phone_id);
            printf("Bin price: %.2f", price);

            break;
        }
    }

    fclose(fp);

    fp = fopen("Test.txt", "w");

    if (fp == NULL)
    {
        printf("Open error");
        exit(2);
    }
    
    fprintf(fp, "Phone id: %12s", phone_id);
    fprintf(fp, "Phone model: %20s", phone_model);
    fprintf(fp, "Phone price: %.2f", price);
    fprintf(fp, "Phone quantity: %d", quant);

    fclose(fp);
}