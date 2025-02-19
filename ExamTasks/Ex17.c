#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[56];
    char id[7];
    double price;
    int code;
}fitness;

fitness *add_member(fitness *members, int *size);
void average_price(fitness *members, int size);
void read_from_bin(char number_id[7]);

int main()
{

    fitness *arr = NULL;
    int size = 0;
    arr = add_member(arr, &size);
    arr = add_member(arr, &size);

    for (int i = 0; i < size; i++)
    {
        printf("%s\n", arr[i].name);
    }
    
    average_price(arr, size);

    return 0;
}

fitness *add_member(fitness *members, int *size)
{
    fitness member1;
    FILE *fp;

    printf("Enter name: ");
    fgets(member1.name, 56, stdin);
    member1.name[strlen(member1.name) - 1] = '\0';
    fflush(stdin);

    printf("Enter id: ");
    fgets(member1.id, 7, stdin);
    member1.id[strlen(member1.id) - 1] = '\0';
    fflush(stdin);

    printf("Enter price: ");
    scanf("%lf", &member1.price);
    fflush(stdin);

    printf("Enter code: ");
    scanf("%d", &member1.code);
    fflush(stdin);

    (*size)++;
    members = (fitness*)realloc(members, sizeof(fitness) * (*size));
    if(!members) exit(1);
    members[(*size) - 1] = member1;

    fp = fopen("members1.Txt", "a");
    if (fp == NULL)
    {
        printf("Open error");
        exit(1);
    }
    
    fprintf(fp, "%ld;%s;%s;%.2lf;%d\n", strlen(member1.name), member1.name, member1.id, member1.price, member1.code);
    fclose(fp);

    return members;
}

void average_price(fitness *members, int size)
{
    int count = 0, flag = 0;
    double average = 0, sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += members[i].price;
        count++;
    }
    average = sum / (double)count;

    for (int i = 0; i < size; i++)
    {
        if (members[i].price < average)
        {
            printf("%s - %s - %.2lf", members[i].name, members[i].id, members[i].price);
            flag = 1;
        }
    }

    if (flag == 0)
    {
        printf("NOT FOUND!");
    }
    

}

void read_from_bin(char number_id[7])
{
    int len_str, code;
    char user_name[56], id[7];
    double price;

    FILE *fp;

    fp = fopen("members.bin", "rb");
    if (fp == NULL)
    {
        printf("Bin open error");
        exit(2);
    }
    
    while (!feof(fp))
    {
        fread(&len_str, sizeof(int), 1, fp);
        fread(user_name, len_str, 1, fp);
        user_name[len_str] = '\0';
        fread(id, 6, 1, fp);
        id[6] = '\0';
        fread(&price, sizeof(double), 1, fp);
        fread(&code, sizeof(int), 1 ,fp);

        if (strcmp(number_id, id) == 0)
        {
            printf("Bin Name: %s", user_name);
            printf("Bin ID: %s", id);
            printf("Bin M_Price: %.2lf", price);
            printf("Bin Locker: %d", code);

            break;
        }
        
    }
    fclose(fp);
    

}