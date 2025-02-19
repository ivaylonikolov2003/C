#include <stdio.h>
const int N = 50;

int main(){
    FILE *fp;
    double arr[N];
    double value;
    int countPositive, countNegative;

    if ((fp = fopen("digits.txt", "r")) == NULL)
    {
        printf("Error file opening!");
    }
    else
    {
        while (fscanf(fp, "%lf", &value) != EOF)
        {
            if (value > 0)
            {
                arr[countPositive] = value;
                countPositive++;
            }else{
                arr[countNegative] = value;
                countNegative++;
            }
            if (countPositive == N || countNegative == N)
            {
                break;
            }
            
        }
    }
    fclose(fp);
    printf("\nThe count of positive values are; %d\n", countPositive);
    printf("The count of negative values are: %d", countNegative);
    

}