#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char StringLen(char str[]);
char CountVowels(char str[]);

int main()
{
    int p;
    char str[100];
    //StringLen(str);
    p = CountVowels(str);
    printf("Vowels in string are: %d", p);

    return 0;
}

char StringLen(char str[])
{
    int count = 0;
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    while (str[count] != '\0')
    {
        count++;
    }
    
    printf("Length of string is %d", count - 1);
}

char CountVowels(char str[])
{
    int i, len, vowels = 0;

    printf("Input string: ");
    fgets(str, 100, stdin);

    len = strlen(str);

    for (i = 0; i < len; i++)
    {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || 
        str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            vowels++;
        }
    }

    return vowels;
    
}