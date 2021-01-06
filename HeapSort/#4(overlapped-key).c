#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int H[100];
int n = 0;

void upHeap(int i)
{
	int tmp;
	if (i == 1) return;
	if (H[i] <= H[i / 2]) return;

	tmp = H[i];
	H[i] = H[i / 2];
	H[i / 2] = tmp;
	upHeap(i / 2);
}

void downHeap(int i)
{
	int tmp;
	int bigger;
	if ((n < (i * 2)) && (n < (i * 2 + 1))) return;
	bigger = i * 2;
	if (n >= i * 2 + 1)
		if (H[i * 2 + 1] > H[bigger])
			bigger = i * 2 + 1;
	if (H[i] >= H[bigger]) return;
	tmp = H[i];
	H[i] = H[bigger];
	H[bigger] = tmp;
	downHeap(bigger);
}

void insert(int key)
{
	H[++n] = key;
	upHeap(n);
}


void rBuildHeap(int i)
{
	if (i > n) return;
	rBuildHeap(2 * i);
	rBuildHeap(2 * i + 1);
	downHeap(i);
}

int delete()
{
	int key = H[1];
	H[1] = H[n--];
	downHeap(1);
	return key;
}

void inPlaceHeapSort()
{
	int i, tmp, m = n;
	rBuildHeap(1);
	for (i = n; i >= 2; i--)
	{
		tmp = delete();
		H[n + 1] = tmp;
	}
	n = m;
}

void print()
{
	int i = 0;
	for (i = 1; i < n + 1; i++)
		printf(" %d", H[i]);
	printf("\n");
}

void main()
{
	int i;
	scanf("%d", &n);

	for (i = 1; i < n+1; i++)
		scanf("%d", &H[i]);

	inPlaceHeapSort();
	print();
}
