#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 36

typedef struct {
    char name[36];
    int age;
    char country[36];
    long int income;
    int count_oscar;
} Artist;

int artist_count = 0;

void AddNewArtist(Artist *ap) {
    Artist artist1;
    printf("Enter name: ");
    fflush(stdin);
    gets(artist1.name);
    printf("Enter age: ");
    scanf("%d", &artist1.age);
    printf("Enter country: ");
    fflush(stdin);
    gets(artist1.country);
    printf("Enter income: ");
    scanf("%ld", &artist1.income);
    printf("Enter Oskars: ");
    scanf("%d", &artist1.count_oscar);
    ap[artist_count] = artist1;
    artist_count++;
}

Artist *ReturnCentrain(Artist *ap, long int income) {
    Artist better_income[artist_count];
    int c = 0;
    for (int i = 0; i < artist_count; i++) {
        if (ap[i].income > income) {
            better_income[c] = ap[i];
            c++;
        }
    }
    return better_income;

}

void FileText() {
    Artist artists[10];
    int artist_size=0;
    int iseof=0;
    char buff, age_str[3], income_str[15], oscar_str[3];
    int counter = 0;
    FILE *f = fopen("test_fie.txt", "r");
    if (f == NULL) {
        printf("Failed to open the file.\n");
        exit(1);
    }
    printf("");
    while (!iseof) {
        Artist artist;
        counter = 0;
        while (1) {
            fread(&buff, sizeof(char), 1, f);
            if (buff == ';') {
                artist.name[counter] = '\0';
                break;
            }
            artist.name[counter] = buff;
            counter++;
        }

        counter = 0;
        memset(age_str, '\0', 3);
        while (1) {
            fread(&buff, sizeof(char), 1, f);
            if (buff == ';') {
                artist.age = atoi(age_str);
                break;
            }
            age_str[counter] = buff;
            counter++;
        }
        counter = 0;
        while (1) {
            fread(&buff, sizeof(char), 1, f);
            if (buff == ';') {
                artist.country[counter] = '\0';
                break;
            }
            artist.country[counter] = buff;
            counter++;
        }
        counter = 0;
        memset(income_str, '\0', 15);
        while (1) {
            fread(&buff, sizeof(char), 1, f);
            if (buff == ';') {
                artist.income = strtoll(income_str, NULL, 10);
                break;
            }
            income_str[counter] = buff;
            counter++;

        }
        memset(oscar_str, '\0', 3);
        counter = 0;
        while (1) {
            if(fread(&buff, sizeof(char), 1, f)==0){
                iseof=1;
                break;
            }
            if (buff == '\n') {
                artist.count_oscar = atoi(oscar_str);
                break;
            }
            oscar_str[counter] = buff;
            counter++;

        }
        artists[artist_size]=artist;
        artist_size++;
    }
    fclose(f);
    for (int i = 0; i < artist_size; ++i) {
        printf("%s %d %s %ld %d\n", artists[i].name, artists[i].age, artists[i].country, artists[i].income, artists[i].count_oscar);

    }
}

int main() {
    Artist artist[MAX_SIZE];
    for (int i=0;i<2;i++){
        AddNewArtist(artist);    
    }
    for (int i=0;i<artist_count;i++){
        printf("%s ",artist[i].name);
                printf("%d\n",artist[i].age);
                    }
    Artist *good_income=ReturnCentrain(artist, 322);
    for (int i=0;i<sizeof(*good_income)/sizeof(good_income[0]);i++){
        printf("%s ",good_income[i].name);
    }
    //FileText();

    return 0;
}