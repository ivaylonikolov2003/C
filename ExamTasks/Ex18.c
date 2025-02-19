#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARTIST 36


typedef struct 
{
    char name[MAX_ARTIST];
    int age;
    char nationality[MAX_ARTIST];
    long int income;
    int number_of_Oscars;
}artist;

int size = 0;

void add_new_artist(artist *artists);
artist *return_certain_income_artist_array(artist *artists, long int income);

int main()
{
    artist arr[MAX_ARTIST];
    for (int i = 0; i < 2; i++)
    {
        add_new_artist(arr);
    }

    for (int i = 0; i < size; i++)
    {
        printf("%s ", arr[i].name);
        printf("%d\n", arr[i].age);
    }
    

    artist *good_income = return_certain_income_artist_array(arr, 322);
    if (good_income != NULL)
    {
        printf("Artists with good income:\n");
        for (int i = 0; i < size; i++)
        {
            printf("%s\n", good_income[i].name);
        }
        free(good_income);
    }
    else
    {
        printf("No artist with good income");
    }

    return 0;
}

void add_new_artist(artist *artists)
{
    if (size >= MAX_ARTIST) 
    {
        printf("Maximum number of artists reached.\n");
        return;
    }

    artist artist1;

    printf("Enter artist name: ");
    fgets(artist1.name, MAX_ARTIST, stdin);
    artist1.name[strlen(artist1.name) - 1] = '\0';
    fflush(stdin);

    printf("Enter age: ");
    scanf("%d", &artist1.age);
    fflush(stdin);

    printf("Enter nationality: ");
    fgets(artist1.nationality, MAX_ARTIST, stdin);
    artist1.nationality[strlen(artist1.nationality) - 1] = '\0';
    fflush(stdin);

    printf("Enter income: ");
    scanf("%ld", &artist1.income);
    fflush(stdin);

    printf("Enter number of Oscars: ");
    scanf("%d", &artist1.number_of_Oscars);
    fflush(stdin);

    
    artists[size] = artist1;
    size++;
    
}

artist *return_certain_income_artist_array(artist *artists, long int income)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (artists[i].income > income)
        {
            count++;
        }
    }

    if (count == 0)
    {
        printf("No such data");
    }
    artist *better_income = malloc(count * sizeof(artist));
    if (better_income == NULL)
    {
        printf("Memory not allocated");
        return NULL;
    }
    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (artists[i].income > income)
        {
            better_income[count] = artists[i];
            count++;
        }
        
    }
    
    return better_income;
}

