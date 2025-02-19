#include <stdio.h>

int main()
{
    int subject[5], total_marks = 0, i;
    double avg_value;

    printf("Enter a marks: ");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &subject[i]);
    }

    for (i = 0; i < 5; i++)
    {
        total_marks += subject[i];
    }
    
    
    avg_value = total_marks / 5;

    printf("Average value is %.2f", avg_value);
    
}