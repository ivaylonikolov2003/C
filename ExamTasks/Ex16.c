#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    char name[31];
    char fak_number[10];
    int group;
    int course;
}student;

void add_student(student *students, int size);
void print_student_by_group(student *students, int size, int group);

int main()
{
    student *arr = NULL;
    int size = 3;

    add_student(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", arr[i].name);
    }
    
    print_student_by_group(arr, 30, 38);

    return 0;
}


void add_student(student *students, int size)
{
    student student1;
    FILE *fp;

    printf("Enter student name: ");
    fgets(student1.name, 31, stdin);
    student1.name[strlen(student1.name) - 1] = '\0';
    fflush(stdin);

    printf("Enter fakulty number: ");
    fgets(student1.fak_number, 10, stdin);
    fflush(stdin);

    printf("Enter group: ");
    scanf("%d", &student1.group);
    fflush(stdin);

    printf("Enter course: ");
    scanf("%d", &student1.course);
    fflush(stdin);

    fp = fopen("Student.txt", "a");

    if (fp == NULL)
    {
        printf("Text file open error");
        exit(1);
    }
    
    fprintf(fp, "%d;%s;%s;%d;%d\n", strlen(student1.name), student1.name, student1.fak_number, student1.group, student1.course);

    fclose(fp);

    size++;
    students = (student*)realloc(students, sizeof(student) * size);
    students[size - 1] = student1;
}

void print_student_by_group(student *students, int size, int group)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (students[i].group == group)
        {
            count++;
        }
        
    }
    
    if (count == 0)
    {
        printf("No such data...");
    }
    
    for (int i = 0; i < size; i++)
    {
        if (students[i].group == group)
        {
            printf("%s - %d", students[i].name, students[i].group);
        }
    }
    
}

void read_print_student(char fak_num[10])
{
    int len_str, group, course;
    char name[31], fakulty_num[10];
    FILE *fp;

    fp = fopen("Student.bin", "rb");
    if (fp == NULL)
    {
        printf("Bin open error");
        exit(2);
    }
    
    while (!feof(fp))
    {
        fread(&len_str, sizeof(int), 1, fp);
        fread(name, len_str, 1, fp);
        name[len_str] = '\0';
        fread(fak_num, 9, 1, fp);
        fak_num[9] = '\0';
        fread(&group, sizeof(int), 1, fp);
        fread(&course, sizeof(int), 1, fp);

        if (fakulty_num == fak_num)
        {
            printf("Bin student name: %s\n", name);
            printf("Bin fakulty number: %s\n", fakulty_num);
            printf("Bin group: %d\n", group);
            printf("Bin course: %d\n", course);
            break;
        }
    }

    fclose(fp);
}