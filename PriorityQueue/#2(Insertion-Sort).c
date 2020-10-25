#include<stdio.h> 
#include<stdlib.h>

void In_InsSort(int*, int);
void Print(int*, int);

void main()
{
	int n;
	int* A = NULL;
	scanf("%d", &n);
	A = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);

	In_InsSort(A, n);
	Print(A, n);
}

void In_InsSort(int* A, int n) {

	int j, tmp;
	for (int i = 1; i < n; i++) {
		tmp = A[i];
		j = i - 1;
		while ((j >= 0) && A[j] > tmp) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = tmp;
	}
}
void Print(int* A, int n) {
	for (int i = 0; i < n; i++) {
		printf(" %d", A[i]);
	}
	printf("\n");
}
