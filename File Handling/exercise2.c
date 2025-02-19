#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file2;
    char fname[20];
    char str;

    printf("Input the file name to be opened: ");
    scanf("%s", fname);

    file2 = fopen(fname, "r");

    if (file2 == NULL)
    {
        printf("Error opening the file");
        exit(1);
    }
    
    printf("\nThe content of the file %s is  :\n", fname);
    str = fgetc(file2);

    while (str != EOF)
    {
        printf("%c", str);
        str = fgetc(file2);
    }
    
    fclose(file2);  
    return 0;
}