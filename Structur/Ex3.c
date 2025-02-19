#include <stdio.h>

typedef struct Student
{
    char name[20];
    double marks;
} student;

struct Class
{
    struct Student class1[20];
    struct Student class2[20];
    struct Student class3[20];
};


int main()
{
    int i, n;
    double average, sum = 0;

    printf("Enter a number of students: ");
    scanf("%d", &n);

    student class[n];

    for (i = 0; i < n; i++)
    {
        printf("Enter a name of the student: ");
        scanf("%s", &class[i].name);

        printf("Enter a marks for student: ");
        scanf("%lf", &class[i].marks);

        sum += class[i].marks;
    }
    
    average = sum / n;

    printf("\nClass average grade: %.2lf", average);

    struct Class gradClass;

    gradClass.class1[0] = class[0];
    gradClass.class1[1] = class[1];

    gradClass.class2[0] = class[2];
    gradClass.class2[1] = class[3];

    gradClass.class3[0] = class[4];
    gradClass.class3[1] = class[5];

    sum = 0;

    for (i = 0; i < n; i++)
    {
        sum += class[i].marks;
    }
    
    average = sum / (n * 3);

    printf("\nGraduating Class Average Grade: %.2lf", average);


    return 0;
}