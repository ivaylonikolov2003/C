#include <stdio.h>


struct Student 
{
    char name[20];
    double grade;
    double average;
};


struct Class 
{
    struct Student students[5];
    double average;
};


struct GraduatingClass 
{
    struct Class classes[3];
    double average;
};

int main() 
{

    struct Student students[5];

    printf("Enter data for %d students:\n", 5);

    for (int i = 0; i < 5; i++) 
    {
        printf("Student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Grade: ");
        scanf("%lf", &students[i].grade);
    }
    
    struct Class classes[3];

    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            classes[i].students[j] = students[i*5 + j];
        }
        
        double sum = 0;
        for (int j = 0; j < 5; j++) 
        {
            sum += classes[i].students[j].grade;
        }
        classes[i].average = sum / 5;
    }
    
    struct GraduatingClass grad_class;
    for (int i = 0; i < 3; i++) 
    {
        grad_class.classes[i] = classes[i];
        
        grad_class.average += classes[i].average;
    }
    
    grad_class.average /= 3;
    
    printf("Class averages:\n");
    
    for (int i = 0; i < 3; i++) 
    {
        printf("Class %d: %.2f\n", i+1, classes[i].average);
    }
    printf("Graduating class average: %.2f\n", grad_class.average);
    
    return 0;
}
