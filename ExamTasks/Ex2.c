#include <stdio.h>
#include <string.h>
#define MAX_STOCKS 1000
typedef struct Products
{
    int product_cod;
    char product_name[10];
    double product_price;
}products;

void input_products(products arr1[], int n);
void max_price_products(products arr1[], int n);
void find_average_price(products arr1[], int n);
void delete_expensive_products(products arr1[], int n);

int main()
{
    products arr[MAX_STOCKS];
    int numStocks;

    printf("Enter the number of stocks (up to %d): ", MAX_STOCKS);
    scanf("%d", &numStocks);

    if (numStocks <= 0 || numStocks > MAX_STOCKS) {
        printf("Invalid number of stocks.\n");
        return 1;
    }

    input_products(arr, numStocks);
    max_price_products(arr, numStocks);
    find_average_price(arr, numStocks);
    delete_expensive_products(arr, numStocks);

    return 0;
}

void input_products(products arr1[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("Enter a %d product\n", i + 1);

        printf("Enter a product key: ");
        scanf("%d", &arr1[i].product_cod);

        printf("Enter a product name: ");
        scanf("%s", arr1[i].product_name);

        printf("Enter a product price: ");
        scanf("%lf", &arr1[i].product_price);
    }
}

void max_price_products(products arr1[], int n)
{
    double max_price = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr1[i].product_price > max_price)
        {
            max_price = arr1[i].product_price;
            count = 1;
        }
        else if (arr1[i].product_price == max_price)
        {
            count++;
        }
    }

    printf("Stocks with the highest price: %s\n", arr1[count - 1].product_name);
    printf("Number of occurrences: %d\n", count);
    
}

void find_average_price(products arr1[], int n)
{
    double sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr1[i].product_name[0] == 'K')
        {
            sum += arr1[i].product_price;
            count++;
        }
    }
    
    if (count > 0)
    {
        double average = sum / (double)count;
        printf("Average is %.2f\n", average);
    }
    else
    {
        printf("No products found starting with K");
    }
    
}


void delete_expensive_products(products arr1[], int n)
{
    double min_price = arr1[0].product_price;

    for (int i = 1; i < n; i++)
    {
        if (arr1[i].product_price < min_price)
        {
            min_price = arr1[i].product_price;
        }
        
    }

    int i = 0;
    while (i < n) 
    {
        if (arr1[i].product_price > 2 * min_price) 
        {
            for (int j = i; j < n - 1; j++) 
            {
                arr1[j] = arr1[j + 1];
            }
            n--;
        } 
        else 
        {
            i++;
        }
    }
    printf("\nStocks with price 2 times greater than the minimum price have been deleted.\n");
}