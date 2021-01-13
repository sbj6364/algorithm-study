#include<stdio.h> 
#include<stdlib.h> 

typedef struct Node {
	int key;
	struct Node* lChild;
	struct Node* rChild;
	int h;
}Node;

int h(Node* N) {
	if (N == NULL)
		return 0;
	return N->h;
}

int MAX(int a, int b) {
	return (a > b) ? a : b;
}

Node* newNode(int key) {
	Node* node = malloc(sizeof(Node));
	node->key = key;
	node->lChild = NULL;
	node->rChild = NULL;
	node->h = 1;
	return(node);
}

Node* rightRotate(Node* y) {
	Node* x = y->lChild;
	Node* T2 = x->rChild;

	x->rChild = y;
	y->lChild = T2;

	y->h = MAX(h(y->lChild), h(y->rChild)) + 1;
	x->h = MAX(h(x->lChild), h(x->rChild)) + 1;

	return x;
}

Node* leftRotate(Node* x) {
	Node* y = x->rChild;
	Node* T2 = y->lChild;

	y->lChild = x;
	x->rChild = T2;

	x->h = MAX(h(x->lChild), h(x->rChild)) + 1;
	y->h = MAX(h(y->lChild), h(y->rChild)) + 1;

	return y;
}

Node* insertItem(Node* w, int key) {
	if (w == NULL)
		return(newNode(key));

	if (key < w->key)
		w->lChild = insertItem(w->lChild, key);
	else if (key > w->key)
		w->rChild = insertItem(w->rChild, key);
	else
		return w;

	w->h = 1 + MAX(h(w->lChild), h(w->rChild));

	return w;
}

Node* minValueNode(Node* w) {
	Node* current = w;

	while (current->lChild != NULL)
		current = current->lChild;

	return current;
}

Node* deleteNode(Node* root, int key) {
	if (root == NULL)
		return root;

	if (key < root->key)
		root->lChild = deleteNode(root->lChild, key);

	else if (key > root->key)
		root->rChild = deleteNode(root->rChild, key);

	else {
		if ((root->lChild == NULL) || (root->rChild == NULL)) {
			Node* temp = root->lChild ? root->lChild :
				root->rChild;

			if (temp == NULL) {
				temp = root;
				root = NULL;
			}
			else *root = *temp;

			free(temp);
		}
		else {
			Node* temp = minValueNode(root->rChild);
			root->key = temp->key;
			root->rChild = deleteNode(root->rChild, temp->key);
		}
	}

	if (root == NULL) return root;

	root->h = 1 + MAX(h(root->lChild), h(root->rChild));

	return root;
}

void preOrder(Node* root) {
	if (root != NULL) {
		printf(" %d", root->key);
		preOrder(root->lChild);
		preOrder(root->rChild);
	}
}

void SpreOrder(Node* root, int n, int* c)
{
	if (root != NULL) {
		if (root->key == n) {
			printf("%d\n", n);
			(*c)++;
		}
		SpreOrder(root->lChild, n, c);
		SpreOrder(root->rChild, n, c);
	}
}

int main() {
	Node* root = NULL;
	char com = 'i';
	int n, c = 0;
	while (com != 'q') {
		scanf("%c", &com);
		
		switch (com){
		case 'i':
			scanf("%d", &n);
			root = insertItem(root, n);
			break;
		case 'd':
			scanf("%d", &n);
			SpreOrder(root, n, &c);
			if (c == 0) {
				printf("X\n");
				c = 0;
			}
			else {
				c = 0;
			}
			root = deleteNode(root, n);
			break;
		case 's':
			scanf("%d", &n);
			SpreOrder(root, n, &c);
			if (c == 0) {
				printf("X\n");
				c = 0;
			}
			else {
				c = 0;
			}
			break;
		case 'p':
			preOrder(root);
			printf("\n");
			break;
		case 'q':
			break;
		}
	}

	return 0;
}
