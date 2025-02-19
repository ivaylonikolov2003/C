#include <stdio.h>

int main()
{
    int m = 10;
    int n, o;
    int *z = &m;


    printf("z Adress of m = %p\n", z);
    printf("*z Value of m = %d\n", *z);
    printf("&m Adress of m = %p\n", &m);
    printf("&n Adress of n = %p\n", &n);
    printf("&o Adress of o = %p\n", &o);
    printf("&z Adress of z = %p\n", &z);

}