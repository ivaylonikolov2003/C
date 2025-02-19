#include <stdio.h>
#include <stdlib.h>
#define MAX_STUDENT 1000
typedef struct Student
{
    int fak_number;
    char name[10];
    int grades[5];
}student;

void fill_student_from_file(student stud[], int size, char *filename);

int main()
{
    student students[MAX_STUDENT];
    fill_student_from_file(students, MAX_STUDENT, "studenti.txt");

    return 0;
}

void fill_student_from_file(student stud[], int size, char *filename)
{
    FILE *fp;

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Open error");
        exit(1);
    }

    for (int i = 0; i < size; i++)
    {
        fscanf(fp, "%d %s", &stud[i].fak_number, stud[i].name);
        for (int j = 0; j < 5; j++)
        {
            fscanf(fp, "%d", &stud[i].grades[j]);
        }
        
    }
    
    fclose(fp);
}


student *return_student_avg_grade(student stud[], int size)
{
    int *result_count = 0;
    int i, j, sum;
    double avg_grade = 0;
    double lowest_average = 6.0;
    int subjects = 5;

    for (i = 0; i < size; i++)
    {
        sum = 0;
        for (j = 0; j < subjects; j++)
        {
            sum += stud[i].grades[j];
        }
        avg_grade = (double)sum / (double)subjects;
        
        if (avg_grade < lowest_average)
        {
            lowest_average = avg_grade;
        }
        
    }

    for (i = 0; i < size; i++)
    {
        sum = 0;
        for (j = 0; j < subjects; j++)
        {
            sum += stud[i].grades[j];
        }
        avg_grade = (double)sum / (double)subjects;
        
        if (avg_grade == lowest_average)
        {
            (*result_count)++;
        }
        
    }   

    student *result = (student*)malloc((*result_count) * sizeof(student));
    int index = 0;

    for (i = 0; i < size; i++)
    {
        sum = 0;
        for (j = 0; j < subjects; j++)
        {
            sum += stud[i].grades[j];
        }

        avg_grade = (double)sum / (double)subjects;
        
        if (avg_grade == lowest_average)
        {
            result[index] = stud[i];
            index++;
        }
        
    }   
    
    return result;

}
