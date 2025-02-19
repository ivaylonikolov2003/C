#include <stdio.h>

int main()
{
    char name[20];

    printf("Enter your full name: ");
    fgets(name, sizeof(name), stdin);

    name[0] = 'X';

    printf("%s ", name);

    return 0;
}