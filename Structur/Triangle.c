#include <stdio.h>
#include <math.h>

typedef struct Point
{
    int roll;
    double x;
    double y;
} point;


int main()
{

    point arr[3];
    int i;

    printf("Input data for x and y:\n");

    for (i = 0; i < 3; i++)
    {
        arr[i].roll = i+1;
        printf("Point number %d", arr[i].roll);

        printf("\nEnter a coordinate for x: ");
        scanf("%lf", &arr[i].x);

        printf("Enter a coordinate for y: ");
        scanf("%lf", &arr[i].y);
    }
    
    double result = 0, ca = 0;

    printf("Three sides of the triangle are: \n");
    for (i = 0; i < 2; i++)
    {
        result = sqrt(pow(arr[i].x - arr[i + 1].x, 2) + pow(arr[i].y - arr[i + 1].y, 2));
        printf("%.2lf\n", result);
    }
    
    ca = sqrt(pow(arr[2].x - arr[0].x, 2) + pow(arr[2].y - arr[0].y, 2));

    printf("%.2lf", ca);
    


    return 0;
}