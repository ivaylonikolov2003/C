#include <stdio.h>
int const N = 2;
int const M = 2;
int const P = N + 2;
int main(){
    int arr[N][M], arr2[N + 2], row, col;

    printf("Enter elements in the array\n");
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < M; col++)
        {
            printf("element - [%d],[%d] : ", row, col);
            scanf("%d", &arr[row][col]);
        }
    }

    for(int i=0; i<P; i++){
        arr2[i] = 0;
    }
		
	for(row=0; row<N; row++)
    {
		for(col=0; col<M; col++)
        {
			if(row==col)
            {
				arr2[0] = arr2[0] + arr[row][col];
            }
        }
    }
	for(row=0; row<N; row++)
    {
		for(col=0; col<M; col++)
        {
			arr2[row+1] = arr2[row+1] + arr[row][col];
        }
    }
	for(row=0; row<N; row++)
    {
		for(col=0; col<M; col++)
        {
			if((row>col) && (arr[row][col]<row+col))
            {
				arr2[P-1] = arr2[P-1] + 1;
            }
        }
    }

    for (int i = 0; i < P; i++)
    {
        printf("%d ", arr[i]);
    }
    
}