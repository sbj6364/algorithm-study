#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct index {
	int a;
	int b;
}Index;

void swap(int* A, int a, int b);
int findpivot(l, r);
int randompivot(l, r);
Index inPlacePartition(int* A, int l, int r, int k);
void inPlaceQuickSort(int* A, int l, int r);
void print(int* A, int n);

	
int main() {

	int n;
	int* A;
	scanf("%d", &n);
	A = (int*)malloc(sizeof(int) * (n + 1));

	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	inPlaceQuickSort(A, 0, n - 1);
	
	print(A, n);
	return 0;
}



void swap(int* A, int a, int b) {
	int tmp;
	tmp = A[a];
	A[a] = A[b];
	A[b] = tmp;
}

int randompivot(l, r) {
	srand(time(NULL));
	int pivot = rand() % (r - l) + l;
	return pivot;
}

Index inPlacePartition(int* A, int l, int r, int k) {
	int i = l, j = r - 1;
	Index ab;
	int p = A[k];
	swap(A, k, r);
	while (i <= j) {
		while (i <= j && A[i] <= A[r]) {
			i++;
		}
		while (j >= i && A[j] >= A[r]) {
			j--;
		}
		if (i < j) {
			swap(A, i, j);
		}
	}
	swap(A, i, r);


	for (int m = i; m >= 0; m--) {
		if (A[m] == A[i]) {
			ab.a = m;
		}
		else break;
	}
	for (int m = i; m <= r; m++) {
		if (A[m] == A[i]) {
			ab.b = m;
		}
		else break;
	}
	return ab;
}

void inPlaceQuickSort(int* A, int l, int r) {
	int k;
	Index ab;
	
	if (l >= r) {
		return;
	}
	k = randompivot(l, r);
	ab = inPlacePartition(A, l, r, k);
	
	inPlaceQuickSort(A, l, ab.a - 1);
	inPlaceQuickSort(A, ab.b + 1, r);
}

void print(int* A, int n) {
	for (int i = 0; i < n; i++) {
		printf(" %d", A[i]);
	}
}
