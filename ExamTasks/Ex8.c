#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee
{  
    char name[10];
    char gender[5];
    double salary;

}employee;

int main()
{


    return 0;
}

void fill_employee(employee *emp, int count, FILE *fp)
{
    employee emp1;

    printf("Enter employee name: ");
    scanf("%s", emp1.name);

    printf("Enter gender: ");
    scanf("%s", emp1.gender);

    printf("Enter salary: ");
    scanf("%lf", emp1.salary);

    fprintf(fp, "%d | %s | %s | %.2lf",strlen(emp1.name) ,emp1.name, emp1.gender, emp1.salary);

    emp = (employee*)malloc(++count * sizeof(employee));
    emp[count - 1] = emp1;

}

employee *return_new_array(employee *emp, int old_size, double salary, int *new_len)
{
    int count = 0;
    for (int i = 0; i < old_size; i++)
    {
        if (emp[i].salary > salary)
        {
            count++;
        }
    }

    employee *new_emp = malloc(sizeof(employee) * count);
    count = 0;

    for (int i = 0; i < old_size; i++)
    {
        if (emp[i].salary > salary)
        {
            new_emp[count] = emp[i];
            count++;
        }
    }
    *new_len = count;
    return new_emp;
}