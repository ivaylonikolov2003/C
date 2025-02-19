#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Medicines
{
    char name[30];
    char registration_number[5];
    char date[10];
    double price;

}medicine;

void fill_medicine(medicine *med, int count, FILE *fp);
void date_expiry(medicine *med, int count_elements, char date);
void search_reg_num(char reg_number[5]);

int main()
{

    
    return 0;
}
//добавяне на ново лекарство
void fill_medicine(medicine *med, int count, FILE *fp)
{
    medicine med1;

    printf("Enter medicine name: ");
    scanf("%30s", med1.name);

    printf("Enter registration number: ");
    scanf("%5s", med1.registration_number);

    printf("Enter date: ");
    scanf("%10s", med1.date);

    printf("Enter medicine price: ");
    scanf("%lf", med1.price);

    fprintf(fp, "%d; %s; %s; %s; %lf", strlen(med1.name), med1.name, med1.registration_number, med1.date, med1.price);

    count++;
    med = realloc(med, sizeof(medicine) * (count));
    if(!med)
    {
        exit(1);
    }
    med[count - 1] = med1;
}

// извеждане информация за всички лекарства с изтекъл срок на годност
void date_expiry(medicine *med, int count_elements, char date)
{
    int current_date = atoi(date);
    for (int i = 0; i < count_elements; i++)
    {
        int medicine_expiry_date = atoi(med[i].date);
        if (current_date > medicine_expiry_date)
        {
            printf("%s - %s", med[i].name, med[i].date);
        }
    }   
}

//по зададен идентификационен номер да се прочете информацията от вече създаден бинарен файл и принтира данни за съответното лекарство в конзолата

void search_reg_num(char reg_number[5])
{
    int len_str;
    char name[30], registration_num[5], date[10];
    double price;

    FILE *fp;

    fp = fopen("Medicine.bin", "rb");

    if (fp == NULL)
    {
        printf("Open error");
        exit(2);
    }
    
    while (fp != EOF)
    {
        fread(&len_str, sizeof(int), 1, fp);
        fread(name, len_str, 1, fp);
        fread(registration_num, 4, 1, fp);
        fread(date, 9, 1, fp);

        name[len_str] = '\0';
        registration_num[4] = '\0';
        date[9] = '\0';
        fread(&price, sizeof(double), 1, fp);

        if (strcmp(reg_number, registration_num) == 0)
        {
            printf("Bin medicine name: %s\n", name);
            printf("Bin price: %.2f\n", price);
            printf("Bin registration number: %s\n", registration_num);

            break;
        }
    }

    fclose(fp);
    
}
