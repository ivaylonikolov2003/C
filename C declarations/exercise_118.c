#include <stdio.h>

int main()
{
    float marks, result = 0;
    int subject = 0;
    printf("Enter a five subject: ");

    while (subject != 5)
    {
        scanf("%f", &marks);

        if (marks < 0 || marks > 100)
        {
            printf("Invalid input!");
        }
        else
        {
            result += marks;
            subject++;
        }
    }
    printf("Average marks = %.2f", result / 5);
}