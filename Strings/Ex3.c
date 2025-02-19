#include <stdio.h>

int main()
{
    char str[100], c;
    int i = 0, count = 0;

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    printf("Enter character to search: ");
    c = getchar();

    while (str[i] != '\0')
    {
        if (str[i] == c)
        {
            count++;
        }
        
        i++;
    }
    
    printf("The number of character in the string is: %d", count);

    return 0;
}