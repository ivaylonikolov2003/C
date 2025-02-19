#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i;
    
    printf("Enter a string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
        
    }
    
    printf("String in upper case is: %s", str);

    return 0;

}