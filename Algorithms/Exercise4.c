#include <stdio.h>
const int N = 50;

int main(){
    FILE *fp;
    int arr[N];
    int count = 0, value;

    if ((fp = fopen("digits.txt", "r")) == NULL)
    {
        printf("Error by file opening!");
    }else
    {
        while (fscanf(fp, "%d", &value) != EOF)
        {
            arr[count] = value;
            count++;
            if (count == N)
            {
                break;
            }
        }
    if (count < N)
    {
        printf("The %d values are read and stored in array.\n", count);
    }else{
        printf("The array is full! Only first %d, number values are stored", N);
    }
    fclose(fp);
    printf("The values are: \n");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
        
    return 0;
    }
    
}