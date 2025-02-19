#include <stdio.h>
#define MAX_SIZE 100
void findCommon2(int A[], int B[], int C[], int m, int n, int p){
    int i = 0, j = 0, k = 0, count = 0;
    int D[MAX_SIZE];

    while (i < m && j < n && k < p)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            D[count] = A[i];
            count++;
            i++;
        }else if (A[i] < B[j])
        {
            i++;
        }else if (B[j] < C[k])
        {
            j++;
        }else{
            k++;
        }
    }
    
    for (int l = 0; l < count; l++)
    {
        printf("%d ", D[l]);
    }
    
}

int main(){
    int A[] = {1, 5, 10, 20, 40, 80, 87};
    int B[] = {6, 7, 20, 80, 87, 100};
    int C[] = {3, 4, 15, 20, 30, 70, 80, 87, 100};

    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);
    int p = sizeof(C) / sizeof(C[0]);

    findCommon2(A, B, C, m, n, p);

    return 0;
}