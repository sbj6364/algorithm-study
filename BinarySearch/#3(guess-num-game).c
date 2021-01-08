#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	int a, b, n, i, mid;
	char c;

	scanf("%d %d %d", &a, &b, &n);
	getchar();
	for (i = 0; i < n; i++) {
		mid = (a + b) / 2;
		scanf("%c", &c);
		if (c == 'Y') {
			a = mid + 1;
		}
		else {
			b = mid;
		}
	}
	printf("%d", a);
}
