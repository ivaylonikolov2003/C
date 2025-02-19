#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Trip
{
    char id[5];
    char date[11];
    int days_duration;
    double price;
}trip;

trip *arr = NULL;
int size = 0;


void add_trip(trip *trips);
void average_duration(trip *trips, int size, int day_duration);
int main()
{
    add_trip(arr);
    add_trip(arr);

    for (int i = 0; i < size; i++)
    {
        printf("%s\n", arr[i].id);
    }
    
    average_duration(arr, size, 5);


    return 0;
}


void add_trip(trip *trips)
{

    trip trip1;
    FILE *fp;

    printf("Enter id: ");
    fgets(trip1.id, 5, stdin);
    trip1.id[strlen(trip1.id) - 1] = '\0';
    fflush(stdin);

    printf("Enter date: ");
    fgets(trip1.date, 11, stdin);
    trip1.date[strlen(trip1.date) - 1] = '\0';
    fflush(stdin);
    
    printf("Enter day duration: ");
    scanf("%d", &trip1.days_duration);
    fflush(stdin);

    printf("Enter price: ");
    scanf("%lf", &trip1.price);
    fflush(stdin);

    arr = (trip*)realloc(arr, sizeof(trip) * (++size));
    arr[size - 1] = trip1;

    fp = fopen("Trip.txt", "a");

    if (fp == NULL)
    {
        printf("Open error");
        exit(1);
    }

    fprintf(fp, "%ld; %s; %s; %ld; %lf\n", strlen(trip1.id), trip1.id, trip1.date, trip1.days_duration, trip1.price);

    fclose(fp);

}   

void average_duration(trip *trips, int size, int day_duration)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i].days_duration > day_duration)
        {
            printf("%s - %s - %d", arr[i].id, arr[i].date, arr[i].days_duration);
            count++;
        }
    }

    if (count == 0)
    {
        printf("No such data!");
    }
    
}