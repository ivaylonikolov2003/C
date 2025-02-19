#include <stdio.h>
#include <string.h>

int main()
{
    char string1[30];
    char string2[30];

    printf("Enter first string: ");
    fgets(string1, sizeof(string1), stdin);

    printf("Enter second string: ");
    fgets(string2, sizeof(string2), stdin);

    if (strlen(string1) > strlen(string2))
    {
        printf("%s", string1);
        printf("Length is %d", strlen(string1));
    }
    else
    {
        printf("%s", string2);
        printf("Length is %d", strlen(string2));
    }


    return 0;
}