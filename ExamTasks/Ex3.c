#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Students
{
    char first_name[10];
    char last_name[10];
    int age;
    double grade;
}students;

int main()
{
    FILE *fp1;

    fp1 = fopen("Students.txt", "w");

    if (fp1 == NULL)
    {
        printf("Error");
        exit(1);
    }

    return 0;
}

void input_students(students *arr, int count, FILE *fp)
{
    students arr1;

    printf("Enter first name: ");
    scanf("%s", arr1.first_name);

    printf("Enter last name: ");
    scanf("%s", arr1.last_name);

    printf("Enter age: ");
    scanf("%d", arr1.age);

    printf("Enter grade: ");
    scanf("%lf", arr1.grade);

    fprintf(fp, "%d | %s | %s | %d | %f \n", strlen(arr1.first_name), arr1.first_name, arr1.last_name, arr1.age, arr1.grade);

    arr = (students*)realloc(arr, ++count * sizeof(students));

    arr[count - 1] = arr1;
}


void average_grade(students *arr, int count)
{
    double avg_grade = 0;

    for (int i = 0; i < count; i++)
    {
        avg_grade += arr[i].grade;
    }
    
    avg_grade /= count;

    for (int i = 0; i < count; i++)
    {
        if (arr[i].grade > avg_grade)
        {
            printf("%s, %s, %d", arr[i].first_name, arr[i].last_name, arr[i].grade);
        }
        
    }
    
}