#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int result = -1;

typedef struct Dictionary {
	int* A;
	int n;
}dic;

int findElement(dic, int);
int rFE(dic, int, int, int);

void main() {
	dic D;
	int key;
	
	scanf("%d %d", &D.n, &key);
	D.A = (int*)malloc(sizeof(int) * D.n);
	for (int i = 0; i < D.n; i++) {
		scanf("%d", &D.A[i]);
	}
	result = findElement(D, key);
	printf(" %d", result);
}

int findElement(dic D, int k) {
	int tmp;
	tmp = rFE(D, k, 0, D.n - 1);
	return tmp;
}
int rFE(dic D, int k, int l, int r) {
	if (l > r) {
		//printf("\nNo Such Key!\n");
		return result;
	}
	int mid = (l + r) / 2;
	/*if (mid == l) {
		if (k < D.A[mid + 1]) return mid;
		else return mid + 1;
	}
	else*/ if (k == D.A[mid]) {
		return mid;
	}
	else if (k < D.A[mid]) {
		return rFE(D, k, l, mid - 1);
	}
	else {
		result = mid;
		return rFE(D, k, mid + 1, r);
	}
}
