#include <stdio.h>

int main()
{
    int m = 300;
    float fx = 300.60;
    char cht = 'z';

    int *pt1 = &m;
    float *pt2 = &fx;
    char *pt3 = &cht;

    printf ( " m = %d\n",m);
    printf ( " fx = %f\n",fx);
    printf ( " cht = %c\n",cht);
    printf("\n Using & operator :\n"); 
    printf("address of m = %p\n", &m);
    printf("address of fx = %p\n", &fx);
    printf("address of cht = %p\n", &cht);
    printf("\n Using & and * operator :\n");
    printf("value of m = %d\n", *(&m));
    printf("value of fx = %f\n", *(&fx));
    printf("value of cht = %c\n", *(&cht));
    printf("\n Using only pointer variable :\n"); 
    printf("address of m = %p\n", pt1);
    printf("address of fx = %p\n", pt2);
    printf("address of cht = %p\n", pt3);
    printf("\n Using only pointer operator :\n");
    printf("value of m = %d\n", *pt1);
    printf("value of fx = %f\n", *pt2);
    printf("value of cht = %c\n", *pt3);




}