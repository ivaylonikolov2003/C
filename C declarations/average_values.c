#include <stdio.h>

int main()
{   

    double itemWeight1, itemWeight2, numberOfPurchase1, numberOfPurchase2, result;

    printf("Enter a value for item1: ");
    scanf("%lf", &itemWeight1);

    printf("Enter a value for item2: ");
    scanf("%lf", &itemWeight2);

    printf("Enter a number of products for first item: ");
    scanf("%d", &numberOfPurchase1);

    printf("Enter a number of products for second item: ");
    scanf("%d", &numberOfPurchase2);

    result = ((itemWeight1 * numberOfPurchase1) + (itemWeight2 * numberOfPurchase2)) / (numberOfPurchase1 + numberOfPurchase2);
    printf("%f", result);

    return 0;

}