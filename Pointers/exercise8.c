#include <stdio.h>
#include <string.h>

void changePosition(char *ch1, char *ch2)
{
    char temp;
    temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;
}

void charPermutation(char *cht, int n, int m)
{
    int i;
    if (n == m)
    {
        printf("%s ", cht);
    }
    else
    {
        for (i = n; i <= m; i++)
        {
            changePosition((cht + n), (cht + i));
            charPermutation(cht, n + 1, m);
            changePosition((cht + n), (cht + i));
        }
        
    }
    
}

int main()
{
    char str[] = "abcd";

    int n = strlen(str);
    printf("Permutation of the string are:\n");

    charPermutation(str, 0, n - 1);
    return 0;
}