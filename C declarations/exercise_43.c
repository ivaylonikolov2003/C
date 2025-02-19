#include <stdio.h>

int main()
{
    int num = 1;
    double sum = 0, result = 0, count = 0;

    printf("Enter a mathematics mark: ");


    while (num != 0 && num > 0)
    {
        scanf("%d", &num);
        if(num <= 0)
        {
            break;
        }
        sum += num;
        count++;
    }

    result = sum / count;

    printf("Average marks in Mathematics: %.2f", result);

    return 0;
}