#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *file1;

    char str[1000];
    char fname[20] = "file1.txt";

    file1 = fopen("file1.txt", "w");

    if(file1 == NULL)
    {
        printf("Error");
        exit(1);
    }

    printf("Input a sentence for the file: ");
    fgets(str, sizeof(str), stdin);
    fprintf(file1, "%s", str);

    fclose(file1);

    printf("\n The file %s created successfully ... !!!\n\n", fname);

    return 0;
}