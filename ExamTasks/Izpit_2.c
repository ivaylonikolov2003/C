#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Picture
{
    int id;
    char name[31];
    char picture_name[31];
    double price;
}picture;

double avg_pictures_prices(picture *pictures, int size, double price);
int count_of_artist(picture *pictures, int size, char letter);
void read_from_bin(char artist_name[31]);

int main()
{
    picture *pictures;
    int n, count = 0;
    double average;
    printf("Enter n: ");
    scanf("%d", &n);

    while (1)
    {
        if (n < 3 || n > 30)
        {
            printf("Enter again n: ");
            scanf("%d", &n);
            continue;
        }
        break;
    }

    pictures = malloc(sizeof(picture) * n);
    if (pictures == NULL)
    {
        printf("Memory error");
        exit(1);
    }
    getchar();
    for (int i = 0; i < n; i++)
    {
        printf("Enter ID: ");
        scanf("%d", &pictures[i].id);
        fflush(stdin);

        printf("Enter artist name: ");
        fgets(pictures[i].name, 31, stdin);
        pictures[i].name[strlen(pictures[i].name) - 1] = '\0';
        fflush(stdin);

        printf("Enter picture name: ");
        fgets(pictures[i].picture_name, 31, stdin);
        pictures[i].picture_name[strlen(pictures[i].picture_name) - 1] = '\0';
        fflush(stdin);

        printf("Enter price: ");
        scanf("%lf", &pictures[i].price);
        fflush(stdin);
    }

    //average = avg_pictures_prices(pictures, n, 50);
    //printf("Average price is: %.2lf", average);

    count = count_of_artist(pictures, n, 'I');
    printf("Count of artist is: %d", count);
    
    free(pictures);
    
    return 0;
}

double avg_pictures_prices(picture *pictures, int size, double price)
{
    double sum = 0, average_price = 0;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (pictures[i].price > price)
        {
            sum += pictures[i].price;
            count++;
        }
    }
    average_price = sum / (double)count;

    if (count == 0)
    {
        return 0;
    }
    else
    {
        return average_price;
    }
}

int count_of_artist(picture *pictures, int size, char letter)
{
    FILE *fp = fopen("info1.txt", "w");
    int count = 0;

    if (fp == NULL)
    {
        printf("Txt open error");
        exit(2);
    }

    for (int i = 0; i < size; i++)
    {
        if (pictures[i].name[0] == letter)
        {
            fprintf(fp, "%d;%s;%.2lfleva\n", pictures[i].id, pictures[i].picture_name, pictures[i].price);
            count++;
        }
        
    }
        
    if (count == 0)
    {
        return 0;
    }
    else
    {
        return count;
    }
}

void read_from_bin(char artist_name[31])
{
    FILE *fp = fopen("icecream.bin", "rb");
    if (fp == NULL)
    {
        printf("Bin open error");
        exit(3);
    }
    int name_len_art, id, pic_len_picture, count = 0;
    double price;
    int status = fread(id, sizeof(int), 1, fp);
    while (status != 0)
    {
        fread(&name_len_art, sizeof(int), 1, fp);
        char artist[name_len_art];
        fread(artist, name_len_art, 1, fp);
        fread(&pic_len_picture, sizeof(int), 1, fp);
        char title[pic_len_picture];
        fread(title, pic_len_picture, 1, fp);
        fread(&price, sizeof(double), 1, fp);

        if (strcmp(artist, artist_name) == 0)
        {
            printf("Picture title - %s\n", title);
            printf("Price - %lf BGN\n", price);
            printf("==========\n");
            count++;
            break;
        }
        status = fread(id, sizeof(int), 1, fp);
    }
    fclose(fp);
    if (count == 0)
    {
        printf("No such data");
    }
    
}