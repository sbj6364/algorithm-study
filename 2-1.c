#include<stdio.h> 
#include<stdlib.h>

void In_SelSort(int*, int);
void Print(int*, int);

int main()
{
	int n;
	int* A = NULL;
	scanf("%d", &n);
	A = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);

	In_SelSort(A, n);
	Print(A, n);
	return 0;
}

void In_SelSort(int* A, int n) {

	int index, tmp;
	for (int i = 0; i < n; i++) {
		index = 0;
		for (int j = 0; j < n - i; j++) {
			if (A[index] < A[j]) index = j;
		}
		tmp = A[index];
		A[index] = A[n - i - 1];
		A[n - i - 1] = tmp;
	}
}
void Print(int* A, int n) {
	for (int i = 0; i < n; i++) {
		printf(" %d", A[i]);
	}
	printf("\n");
}
