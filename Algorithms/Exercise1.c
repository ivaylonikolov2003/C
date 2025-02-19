#include <stdio.h>
#include <string.h>
const int N = 3;

struct employe
{
    char name[30];
    int age;
    float salary;
};

int main()
{
    struct employe Workers[N];
    char Name[30]; 
    int Age;
    float Salary;
    for (int i = 0; i < N; i++)
    {
        printf("Enter Name for worker %d: ", i+1);
        scanf("%[^\n]", Name);
        strcpy(Workers[i].name, Name);
        printf("Enter age %d: ", i + 1);
        scanf("%d", &Age);
        Workers[i].age = Age;
        printf("Enter salary for worker %d: ", i + 1);
        scanf("%f", &Salary);
        fflush(stdin);
        Workers[i].salary = Salary;
    }

    printf("\nData for workers with salary above 700:\n");
    for (int i = 0; i < N; i++)
    {
        if (Workers[i].salary > 700.0)
        {
            printf("Name:  %s;  Age:   %d;  Salary:  %.2f\n", Workers[i].name, Workers[i].age, Workers[i].salary);
        }
    }
    
    return 0;
}
