#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char name[4];
    float price;
} product_t;

product_t *return_new_array(product_t *old_arr, int old_arr_len, float price, int *new_len);
product_t *return_new_array_better(product_t *old_arr, int old_arr_len, float price, int *new_len);
void print_products_from_array(product_t *prods, int len);

int main(int argc, char **argv){
    product_t pr1 = {.name="1", .price = 12.3};
    product_t pr2 = {.name="2", .price = 13.3};
    product_t pr3 = {.name="3", .price = 14.3};
    product_t prs[] = {pr1,pr2,pr3};
    int new_len;
    // product_t *new_arr = return_new_array(prs, 3, 14, &new_len);
    product_t *new_arr = return_new_array_better(prs, 3, 11, &new_len);
    print_products_from_array(new_arr, new_len);
    free(new_arr);
    return 0;
}
product_t *return_new_array(product_t *old_arr, int old_arr_len, float price, int *new_len){
    int count = 0;
    for (int i = 0; i < old_arr_len; i++)
    {
        if(old_arr[i].price > price){
            count++;
        }
    }
    product_t *new_arr = malloc(sizeof(product_t)*count);
    count = 0;
    for (int i = 0; i < old_arr_len; i++)
    {
        if(old_arr[i].price > price){
            new_arr[count++] = old_arr[i];
        }
    }
    *new_len = count;
    return new_arr;
}
product_t *return_new_array_better(product_t *old_arr, int old_arr_len, float price, int *new_len){
    product_t *new_arr = NULL;
    int count = 0;
    for (int i = 0; i < old_arr_len; i++)
    {
        if(old_arr[i].price > price){
            count++;
            product_t *temp = realloc(new_arr, sizeof(product_t)*count);
            if(temp == NULL){
                fprintf(stderr, "No memory!\n");
                exit(-1);
            }
            new_arr = temp;
            new_arr[count-1] = old_arr[i];
        }
    }
    *new_len = count;
    return new_arr;
}
void print_products_from_array(product_t *prods, int len){
    for (int i = 0; i < len; i++)
    {
        printf("%s %f\n", prods[i].name, prods[i].price);
    }
}