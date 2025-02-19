#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct item_t {
    char name[32];  
    double price;
    int amount;
};

typedef struct item_t item;

int main() 
{
    item chair = {.name="Chair",.price = 13.99,.amount = 1};
    item table = {.name="Table",.price = 42.00,.amount = 8};
    item cups = {.name="Cups",.price = 5.98,.amount = 6};
    item plates = {.name="Dishes",.price = 21.02,.amount = 6};

    int guests;

    printf("Enter amount of guests:\n");
    scanf("%d", &guests);

    getc(stdin);
    double total_cost = 0;
    char input[20];
    int needed_chairs = guests, needed_cups = guests, needed_tables = guests, needed_dishes = guests;

    while (1) 
    {
        printf("Enter the item or PARTY! to stop: ");
        scanf("%s", input);

        if(strcmp(input, "Chair") == 0)
        {
            needed_chairs -= chair.amount;
            total_cost += chair.price;
            continue;
        }
        if(strcmp(input, "Table") == 0)
        {
            needed_tables -= table.amount;
            total_cost += table.price;
            continue;
        }
        if(strcmp(input, "Cups") == 0)
        {
            needed_cups -= cups.amount;
            total_cost += cups.price;
            continue;
        }
        if(strcmp(input, "Dishes") == 0)
        {
            needed_dishes -= plates.amount;
            total_cost += plates.price;
            continue;
        }
        if(strcmp(input, "PARTY!") == 0)
        {
            break;
        }
        printf("Invalid Input!\n");
        }

    if(needed_chairs > 0)
    {
        printf("Guests need %d more chairs!\n", needed_chairs);
    }
    if(needed_tables > 0)
    {
        int count = 0;
        while (needed_tables > 0)
        {
            needed_tables -= table.amount;
            count++;
        }
        
        printf("Guests need %d more tables!\n", count);
    }
    if(needed_cups > 0)
    {
        int count = 0;
        while (needed_cups > 0)
        {
            needed_cups -= cups.amount;
            count++;
        }
        
        printf("Guests need %d more cups!\n", count);
    }
    if(needed_dishes > 0)
    {
        int count = 0;
        while (needed_dishes > 0)
        {
            needed_dishes -= plates.amount;
            count++;
        }
        printf("Guests need %d more dishes!\n", count);
    }

    printf("Haralampi has spent: %0.2lf BGN!", total_cost);


    return 0;
}
