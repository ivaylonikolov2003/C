#include <stdio.h>

int main()
{
    char str[100];
    int count = 0, i = 0;

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    while (str[i] != '\0')
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            count++;
        }
        
        i++;
    }
    
    printf("Total numbers of words in the string are: %d", count);
    return 0;
}