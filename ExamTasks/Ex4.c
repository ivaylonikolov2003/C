#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Products
{
    char product_name[30];
    int product_id;
    char date_expiry[10];
    double product_price;
}products;


int main()
{
    products *product;

    FILE *fp;

    fp = fopen("in.bin", "wb");

    if (fp == NULL)
    {
        printf("Open error");
        exit(1);
    }
    
    return 0;
}

void input_product(products *arr, int count, FILE *fp1)
{
    products product;

    printf("Enter product name: ");
    scanf("%s", product.product_name);

    printf("Enter product id: ");
    scanf("%d", &product.product_id);

    printf("Enter expiry date: ");
    scanf("%s", product.date_expiry);

    printf("Enter product price: ");
    scanf("%lf", product.product_price);

    fprintf(fp1, "%d; %s; %d; %s; %.2f", strlen(product.product_name), product.product_name, product.product_id, product.date_expiry, product.product_price);

    
    arr = (products*)malloc(++count * sizeof(products));
    arr[count - 1] = product;
}

products *return_bigger_price(products *arr, double price, int size, int *new_len)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].product_price > price)
        {
            count++;
        }
        
    }
    
    products *new_prod = malloc(sizeof(products) * count);
    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].product_price > price)
        {
            new_prod[count] = arr[i];
            count++;
        }
        
    }

    *new_len = count;
    return new_prod;
} 