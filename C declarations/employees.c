#include <stdio.h>

int main()
{   
    char id[10];
    int workingHours, receivedPerHour;
    double result;

    printf("Employee ID: ");
    scanf("%s", &id);

    printf("Working hours: ");
    scanf("%d", &workingHours);

    printf("Salary: ");
    scanf("%d", &receivedPerHour);

    result = workingHours * receivedPerHour;

    printf("%s\n", id);
    printf("%.2f", result);

    return 0;
}