#include<stdlib.h>
#include<stdio.h>
#include<string.h>
const int N = 3;
struct employe
{
    char name[30];
    char lastName[30];
    char possition[30];
    double salary;
};

int main(){
    struct employe workers[N];
    char Position[20];

    for (int i = 0; i < N; i++)
    {
        printf("Enter First Name for worker %d: ", i+1);
        scanf("%s", workers[i].name);
        printf("Enter Last Name %d: ", i + 1);
        scanf("%s", workers[i].lastName);
        printf("Enter Position %d: ", i + 1);
        scanf("%s", workers[i].possition);
        printf("Enter salary for worker %d: ", i + 1);
        scanf("%lf", &workers[i].salary);
        fflush(stdin);
    }

    printf("Enter Position: ");
    scanf("%s", Position);

    for (int i = 0; i < N; i++)
    {
        if (strcmp(workers[i].possition, Position) == 0)
        {
            printf("Name:  %s;  LastName:   %s;  Position:    %s;    Salary:  %.2f\n", workers[i].name, workers[i].lastName, workers[i].possition, workers[i].salary);
        }
    }
    return 0;
    
    
}
