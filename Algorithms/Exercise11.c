#include <stdio.h>
#include <stdlib.h>

int main(){

    int x = 2;


    do
    {
        x = 2 * x + 10;
    } while (x <= 100);
    

    printf("Value of x is %d", x);
}