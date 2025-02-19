#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cage
{
    char animal_type[10];
    int age;
    char id[10];
}cage;

void add_animal(cage *animals, int size, FILE *fp);
cage *return_little_animal(cage *animals, int old_len, int age, int *new_len);
void read_from_bin(char id[10]);
void write_to_bin_file();

int main()
{
    cage *arr = NULL;
    int count = 0;
    FILE *fp = fopen("test.txt", "w");
    add_animal(arr, count, fp);
    write_to_bin_file();
    read_from_bin("1234567");
    
    return 0;
}


void add_animal(cage *animals, int size, FILE *fp)
{
    cage animal1;

    printf("Enter animal type: ");
    scanf("%10s", animal1.animal_type);

    printf("Enter animal age: ");
    scanf("%d", &animal1.age);

    printf("Enter id: ");
    scanf("%10s", animal1.id);

    fprintf(fp, "%d; %s; %d; %s", strlen(animal1.animal_type), animal1.animal_type, animal1.age, animal1.id);

    size++;
    animals = realloc(animals, sizeof(cage) * size);
    if (!animals)
    {
        exit(1);
    }
    
    animals[size - 1] = animal1;
}

cage *return_little_animal(cage *animals, int old_len, int age, int *new_len)
{
    int count = 0;
    for (int i = 0; i < old_len; i++)
    {
        if (animals[i].age < age)
        {
            count++;
        }
    }

    cage *new_animals = malloc(sizeof(cage) * count);
    count = 0;

    for (int i = 0; i < old_len; i++)
    {
        if (animals[i].age < age)
        {
            new_animals[count] = animals[i];
            count++;
        }
    }
     
    *new_len = count;
    return new_animals;
}

void read_from_bin(char id[10])
{

    int len_str, age;
    char type_animal[10], animal_id[10];

    FILE *fp;
    fp = fopen("Animal.bin", "rb");

    if (fp == NULL)
    {
        printf("Open error");
        exit(2);
    }
    
    while (!feof(fp))
    {
        fread(&len_str, sizeof(int), 1, fp);
        fread(type_animal, len_str, 1, fp);
        fread(animal_id, 9, 1, fp);

        type_animal[len_str] = '\0';
        animal_id[9] = '\0';
        fread(&age, sizeof(int), 1, fp);

        if (strcmp(animal_id, id) == 0)
        {
            printf("Bin animal type: %s\n", type_animal);
            printf("Bin age: %d\n", age);
            printf("Bin id: %s\n", animal_id);
        }
        break;
    }
    
    fclose(fp);
}

void write_to_bin_file()
{
    FILE *fp;

    fp = fopen("Animal.bin", "wb");

    if (fp == NULL)
    {
        printf("Open error");
        exit(3);
    }
    
    int len_str = 3;
    char *animal_type = "cat";
    char *id = "1234567\0";
    int age = 5;

    fwrite(&len_str, sizeof(int), 1, fp);
    fwrite(animal_type, len_str, 1, fp);
    fwrite(id, sizeof(id), 1, fp);
    fwrite(&age, sizeof(int), 1, fp);

    fclose(fp);
}