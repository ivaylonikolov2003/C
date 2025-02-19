#include <stdio.h>

int main()
{
    int password, x = 10;

    while (x != 0) 
    {
        printf("Enter a password: ");
        scanf("%d", &password);

        if (password == 1234)
        {
            printf("Correct password!");
            x = 0;
        }
        else
        {
            printf("Invalid password, try another");
        }
        printf("\n");
    }
    return 0;
}