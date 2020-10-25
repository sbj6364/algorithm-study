//Max_Heap, D/S_Array

#include<stdio.h> 
#include<stdlib.h>

int H[100];
int n = 0;

void Insert(int);
int Delete();
void UpHeap(int);
void DownHeap(int);
void Print();

void main()
{
	char ord = 'i';
	int key;

	while (ord != 'q') {
		scanf("%c", &ord);
		switch (ord) {
		case 'i':
			scanf("%d", &key);
			Insert(key);
			printf("0\n");
			getchar();
			break;
		case 'd':
			printf("%d\n", Delete());
			getchar();
			break;
		case 'p':
			Print();
			getchar();
			break;
		}
	}

}

void Insert(int key) {
	H[++n] = key;
	UpHeap(n);
}
int Delete() {
	int max = H[1];
	H[1] = H[n--];
	DownHeap(1);
	return max;
}
void UpHeap(int i) {
	int tmp;
	if (i == 1) return;
	if (H[i] <= H[i / 2]) return;

	tmp = H[i];
	H[i] = H[i / 2];
	H[i / 2] = tmp;
	UpHeap(i / 2);
}
void DownHeap(int i) {
	int tmp, bigger;
	if ((n < i * 2) && (n < i * 2 + 1)) return;
	bigger = i * 2;
	if (H[i * 2] < H[i * 2 + 1])
		bigger = i * 2 + 1;
	if (H[i] > H[bigger]) return;
	tmp = H[i];
	H[i] = H[bigger];
	H[bigger] = tmp;
	DownHeap(bigger);
}
void Print() {
	for (int i = 1; i < n + 1; i++) {
		printf(" %d", H[i]);
	}
	printf("\n");
}
