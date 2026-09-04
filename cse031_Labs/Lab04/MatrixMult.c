
#include <stdio.h>
#include <stdlib.h>

//got help from Dina Seoudi
int** matMult(int **a, int **b, int size) {
	// (4) Implement your matrix multiplication here. 
	// You will need to create a new matrix to store the product.
	int i, j, k;
	int **c = (int**)malloc(size * sizeof(int*));
	for(i = 0; i < size; i++){
		*(c + i) = (int*)malloc(size * sizeof(int));
		for(j = 0; j < size; j++){
			*(*(c + i) + j) = 0;
		}
	}

	for(i = 0; i < size;i++){
		for(k = 0;k < size;k++){
			int aik = *(*(a + i) + k);
			for(j = 0; j < size; j++){
				*(*(c + i) + j) += aik * (*(*(b + k) + j));
			}
		}
	}
	return c;
}

void printArray(int **arr, int n) {
	// (2) Implement your printArray function here
	for (int i = 0; i < n; i++)
	{	
		for (int j = 0; j < n; j++)
		{
			printf("%d ", *(*(arr + i) + j));
		}
		printf("\n");
	}
	
}

int main() {
	int n = 0;
	int **matA, **matB, **matC;
	// (1) Define 2 (n x n) arrays (matrices).
	scanf("%i", &n); 
	matA = (int**)malloc(n*sizeof(int*));
	matB = (int**)malloc(n*sizeof(int*));

	for (int i = 0; i < n; i++)
	{	
		*(matA+i) = (int*)malloc(n*sizeof(int));
		*(matB+i) = (int*)malloc(n*sizeof(int));
		
	}

	for (int i = 0; i < n; i++)
	{	
		for (int j = 0; j < n; j++)
		{
			*(*(matA + i) + j) = i+j;
			*(*(matB + i) + j) = i-j;
		}
	}
	

	// (3) Call printArray to print out the 2 arrays here.
	printArray(matA, n);
	printf("\n");
	printArray(matB, n);
	printf("\n");

	
	// (5) Call matMult to multiply the 2 arrays here.
	matC = matMult(matA, matB, n);
	
	// (6) Call printArray to print out resulting array here.
	printArray(matC, n);

    return 0;
}