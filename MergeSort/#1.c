#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

void partition(Node*, Node**, Node**, int);
Node* merge(Node**, Node**);
void mergeSort(Node**, int);
void addList(Node**, int);
void print(Node*);

int main() {
	int n, value;
	Node* L = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &value);
		addList(&L, value);
	}
	mergeSort(&L, n);
	print(L);

	return 0;
}

void partition(Node* L, Node** L1, Node** L2, int n) {
	Node* p = L;
	*L1 = L;
	for (int i = 0; i < (n / 2) - 1; i++) {
		p = p->next;
	}
	*L2 = p->next;
	p->next = NULL;
}

Node* merge(Node** L1, Node** L2) {
	Node* p, * L;
	Node* A = *L1;
	Node* B = *L2;
	if (A->data <= B->data) {
		L = A;
		A = A->next;
		p = L;
	}
	else {
		L = B;
		B = B->next;
		p = L;
	}
	while ((A != NULL) && (B != NULL)) {
		if (A->data <= B->data) {
			p->next = A;
			A = A->next;
			p = p->next;
		}
		else {
			p->next = B;
			B = B->next;
			p = p->next;
		}
	}
	while (A != NULL) {
		p->next = A;
		p = A;
		A = A->next;
	}
	while (B != NULL) {
		p->next = B;
		p = B;
		B = B->next;
	}
	return L;
}

void mergeSort(Node** L, int n) {
	Node* L1, * L2, * p = *L;
	if (n > 1) {
		partition(p, &L1, &L2, n);
		if ((n % 2) == 0) {
			mergeSort(&L1, n / 2);
			mergeSort(&L2, n / 2);
		}
		else {
			mergeSort(&L1, n / 2);
			mergeSort(&L2, (n / 2) + 1);
		}
		*L = merge(&L1, &L2);
	}
}

void addList(Node** L, int value) {
	Node* p = *L;
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = value;
	newnode->next = NULL;
	if (*L == NULL) {
		*L = newnode;
	}
	else {
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = newnode;
	}
}

void print(Node* L) {
	Node* p = L;
	while (p != NULL) {
		printf(" %d", p->data);
		p = p->next;
	}
	printf("\n");
}
