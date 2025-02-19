#include <stdio.h>

int main()
{
    FILE *fileptr;
    int count_lines = 0;
    char filechar[40], chr;

    printf("Enter the file name: ");
    scanf("%s", filechar);

    fileptr = fopen(filechar, "r");

    chr = getc(fileptr);

    while (chr != EOF)
    {
        if (chr == 'n')
        {
            count_lines++;
        }
        
        chr = getc(fileptr);
    }

    fclose(fileptr);

    printf("The are %d number of lines in %s file", count_lines, filechar);

    return 0;

}