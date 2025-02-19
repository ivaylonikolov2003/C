#include <stdio.h>

void decByn(int n){
    if (n > 0)
    {
        decByn(n / 2);
        printf("%d ", n%2);
    }
    
}

int main(){

    decByn(87);
}