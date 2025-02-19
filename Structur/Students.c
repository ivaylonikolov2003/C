#include <stdio.h>

typedef struct Students
{
    char first_name[50];
    char second_name[50];
    int num_of_students;
    double marks;
} students;


int main()
{
    students stud[2];
    int i;

    printf("Enter information of the students: ");

    for (i = 0; i < 2; i++)
    {
        stud[i].num_of_students = i + 1;

        printf("\nStudent number: %d", stud[i].num_of_students);

        printf("\nEnter first name: ");
        scanf("%s", stud[i].first_name);

        printf("Enter second name: ");
        scanf("%s", stud[i].second_name);

        printf("Enter marks: ");
        scanf("%lf", &stud[i].marks);

    }
    

    printf("Display information: \n");

    for (i = 0; i < 2; i++)
    {
        printf("\nStudent number: %d\n", i+1);
        printf("First Name: %s", stud[i].first_name);
        printf("\nSecond Name: %s", stud[i].second_name);
        printf("\nMarks: %.2lf", stud[i].marks);
    }
    

    return 0;
}