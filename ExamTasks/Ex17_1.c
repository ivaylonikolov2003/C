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
int main()
{

    fitness *arr = NULL;
    int size = 0;
    arr = add_member(arr, &size); //без това равно указателя сочи към стария адрес и все едно не си записал нищо
    arr = add_member(arr, &size); //адрес към размера защото не го знаем иначе като се добавя елемент
    arr = add_member(arr, &size);
    // for(int i = 0; i < size ; i++){
    //     printf("%s\n", arr[i].name); //проверка дали сме записали в паметта
    // }
    average_price(arr, size); //това си работи
    return 0;
}

fitness *add_member(fitness *members, int *size) //промених го да връща указател заради попълването в динамичната памет
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
    // fflush(stdin);
    getc(stdin);

    (*size)++;
    members = (fitness*)realloc(members, sizeof(fitness) * (*size));
    if(!members) exit(1);
    members[(*size) - 1] = member1;

    fp = fopen("members.Txt", "a");
    if (fp == NULL)
    {
        printf("Open error");
        exit(1);
    }
    
    fprintf(fp, "%ld;%s;%s;%lf;%d", strlen(member1.name), member1.name, member1.id, member1.price, member1.code);
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
            printf("%s - %s - %.2lf\n", members[i].name, members[i].id, members[i].price);
            flag = 1;
        }
    }

    if (flag == 0)
    {
        printf("NOT FOUND!");
    }
    

}