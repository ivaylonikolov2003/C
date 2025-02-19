#include <stdio.h>

int main()
{
    FILE *fptr;
    int count_lines;
    char filename[40], chr, chr1;

    printf("Enter the file name: ");
    scanf("%s", filename);

    fptr = fopen(filename, "r");

    printf("The content of the file is: ");
    chr = fgetc(fptr);

    while (chr != EOF)
    {
        printf("%c", chr);
        chr = fgetc(fptr);
    }

    fclose(fptr);

    fptr = fopen(filename, "r");

    char line[256];
    int lines = 0;
    while (fgets(line, 256, fptr))
    {
        printf("%d.%s", lines++, line);
    }
    

    fclose(fptr);

    printf("\nThe lines in the file are: %d", lines);

    return 0;
}