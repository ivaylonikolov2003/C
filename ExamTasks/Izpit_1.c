#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct IceCream
{
    char id[3];
    char name[21];
    int weight;
    double price;
}icecream;

double all_price(icecream *icecreams, int size, char letter);
int count_save_element(icecream *icecreams, int size, double price, int weight);
void read_from_bin(char id[2]);
void zadacha_4_test();

int main()
{
    icecream *icecreams;
    int n, count = 0;
    double sum = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    while (1)
    {
        if (n < 5 || n > 15)
        {
            printf("Enter n: ");
            scanf("%d", &n);
            continue;
        }
        break;
    }
    
    icecreams = malloc(sizeof(icecream) * n);
    if (icecreams == NULL)
    {
        printf("Memory error");
        exit(1);
    }
    getchar();
    for (int i = 0; i < n; ++i)
    {
        printf("Enter id: ");
        fgets(icecreams[i].id, 3, stdin);
        icecreams[i].id[2] = '\0';
        fflush(stdin);

        printf("Enter name: ");
        fgets(icecreams[i].name, 21, stdin);
        icecreams[i].name[strlen(icecreams[i].name) - 1] = '\0';
        fflush(stdin);

        printf("Enter weight: ");
        scanf("%d", &icecreams[i].weight);
        fflush(stdin);

        printf("Enter price: ");
        scanf("%lf", &icecreams[i].price);
        fflush(stdin);
    }
    //sum = all_price(icecreams, n, 's');
    //printf("Sum is %.2lf", sum);
    //count = count_save_element(icecreams, n, 50, 20);
    //printf("Function 2 counter is: %d", count);
    zadacha_4_test();
    read_from_bin("A2");

    free(icecreams);
    return 0;
}


double all_price(icecream *icecreams, int size, char letter)
{
    double sum = 0;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (icecreams[i].name[0] == letter)
        {
            sum += icecreams[i].price;
            count++;
        }
        
    }
    
    if (count == 0)
    {
        return 0;
    }
    else
    {
        return sum;
    }

}

int count_save_element(icecream *icecreams, int size, double price, int weight)
{
    FILE *fp = fopen("info.txt", "w");
    int count = 0;

    if (fp == NULL)
    {
        printf("Open error");
        exit(2);
    }
    
    for (int i = 0; i < size; i++)
    {
        if (icecreams[i].price < price && icecreams[i].weight > weight)
        {
            fprintf(fp, "%s;%s;%d;%.2lf\n", icecreams[i].id, icecreams[i].name, icecreams[i].weight, icecreams[i].price);
            count++;
        }
        
    }
    fclose(fp);

    if (count == 0)
    {
        return 0;
    }
    else
    {
        return count;
    }
}

void read_from_bin(char id[2])
{
    int name_str, weight, count = 0;
    char ID[3];
    double price;

    FILE *fp = fopen("icecream.bin", "rb");
    if (fp == NULL)
    {
        printf("Bin open error");
        exit(3);
    }
    int status = fread(ID, 2, 1, fp);
    while (status != 0)
    {
        fread(&name_str, sizeof(int), 1, fp);
        char name[name_str];
        fread(name, name_str, 1, fp);
        name[name_str] = '\0';
        fread(&weight, sizeof(int), 1, fp);
        fread(&price, sizeof(double), 1, fp);
        if (strcmp(ID, id) == 0)
        {
            printf("==========\n");
            printf("Ice Cream - %s\n", name);
            printf("Price - %.2lf BGN\n", price);
            printf("==========\n");
            count++;
        }
        status = fread(ID, 2, 1, fp);
    }
    fclose(fp);
    if (count == 0)
    {
        printf("No such data");
    }
    
}

void zadacha_4_test(){
    FILE *fp = fopen("icecream.bin", "wb");
    if(!fp) exit(1);
    char *code = "A2";
    int name_len = 4;
    char *name = "ABC";
    int weight = 12;
    double price = 12.2;
    fwrite(code, 1, 2, fp);
    fwrite(&name_len, sizeof(int), 1, fp);
    fwrite(name, 1, name_len, fp);
    fwrite(&weight, sizeof(int), 1, fp);
    fwrite(&price, sizeof(double), 1, fp);
    fclose(fp);
}