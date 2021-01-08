#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Dictionary {
	int* A;
	int n;
}dic;

int searchKey(dic, int);

void main() {
	dic D;
	int key, result;
	
	scanf("%d %d", &D.n, &key);
	D.A = (int*)malloc(sizeof(int) * D.n);
	for (int i = 0; i < D.n; i++) {
		scanf("%d", &D.A[i]);
	}
	result = searchKey(D, key);
	printf(" %d", result);

	free(D.A);
}

int searchKey(dic D, int k) {
	int l = 0, r = D.n - 1, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (k == D.A[mid]) {
			return mid;
		}
		else if (k < D.A[mid]) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
}
