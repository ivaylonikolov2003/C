#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Market
{
    char name[31];
    int id;
    char expiry_date[11];
    double price;
}market;

market *add_product(market *products, int *size);
market *return_products_array(market *products, int size, double price);
void read_write_files();

int main()
{
    market *arr = NULL;
    int size = 0;
    arr = add_product(arr, &size);

    for (int i = 0; i < size; i++)
    {
        printf("%s\n", arr[i].name);
    }
    
    market *new_arr = return_products_array(arr, size, 10);
    for (int i = 0; i < size; i++)
    {
        printf("%s ", new_arr[i].name);
    }

    read_write_files();
    
    return 0;
}

market *add_product(market *products, int *size)
{
    market product1;
    FILE *fp;

    printf("Enter name: ");
    fgets(product1.name, 31, stdin);
    product1.name[strlen(product1.name) - 1] = '\0';
    fflush(stdin);

    printf("Enter id: ");
    scanf("%d", &product1.id);
    fflush(stdin);

    printf("Enter expiry date: ");
    fgets(product1.expiry_date, 11, stdin);
    fflush(stdin);

    printf("Enter price: ");
    scanf("%lf", &product1.price);
    fflush(stdin);

    (*size)++;
    products = (market*)realloc(products, sizeof(market) * (*size));
    products[(*size) - 1] = product1;

    fp = fopen("In.bin", "wb");

    if (fp == NULL)
    {
        printf("Open error");
        exit(1);
    }
    
    fwrite(products, sizeof(market), *size, fp);
    fclose(fp);

    return products;
}

market *return_products_array(market *products, int size, double price)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (products[i].price > price)
        {
            count++;
        }
    }

    market *new_products = malloc(sizeof(market) * count);
    count = 0;

    for (int i = 0; i < size; i++)
    {
        if (products[i].price > price)
        {
            new_products[count] = products[i];
            count++;
        }
    }

    return new_products;
}

void read_write_files()
{
    FILE *binary_file = fopen("In.bin", "rb");
    FILE *text_file = fopen("out.txt", "w");

    if (binary_file == NULL || text_file == NULL)
    {
        printf("File open error.\n");
        return;
    }

    market product;
    int count = 0;

    while (fread(&product, sizeof(market), 1, binary_file) == 1)
    {
        fprintf(text_file, "Name: %s\n", product.name);
        fprintf(text_file, "ID: %d\n", product.id);
        fprintf(text_file, "Expiry Date: %s\n", product.expiry_date);
        fprintf(text_file, "Price: %.2lf\n", product.price);
        count++;
    }

    fclose(binary_file);
    fclose(text_file);

    FILE *printed_file;
    char line[100];


    printf("\nContents of In.bin:\n");
    binary_file = fopen("In.bin", "rb");
    if (binary_file != NULL)
    {
        while (fgets(line, sizeof(line), binary_file) != NULL)
        {
            printf("Name: %s\n", product.name);
            printf("ID: %d\n", product.id);
            printf("Expiry Date: %s\n", product.expiry_date);
            printf("Price: %.2lf\n", product.price);
        }
        fclose(binary_file);
    }

    printf("\n");

    printf("Contents of out.txt:\n");
    text_file = fopen("out.txt", "r");
    if (text_file != NULL)
    {
        while (fgets(line, sizeof(line), text_file) != NULL)
        {
            printf("%s", line);
        }
        fclose(text_file);
    }

    printf("Total Products: %d\n", count);
}
