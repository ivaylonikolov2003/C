#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;

    fptr = fopen("file.txt", "w");

    if (fptr == NULL)
    {
        printf("Error");
        exit(1);
    }
    
    fputs("C is a fun programming language\n", fptr);
    fputs("And, I love using C programming", fptr);

    fclose(fptr);

    fptr = fopen("file.txt", "r");
    char content[1000];

    if (fptr != NULL)
    {
        while (fgets(content, 1000, fptr))
        {
            printf("%s", content);
        }
    }
    else
    {
        printf("Error");
    }

    fclose(fptr);
    
    return 0;
}