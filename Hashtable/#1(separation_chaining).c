#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
}node;

int hashfunction(int, int);
void insert(node*, int, int);
void search(node*, int, int);
void deletekey(node*, int, int);
void printkey(node*, int);

int main() {

    int M, i, num;
    char ord;
    node* hashtable;

    scanf("%d", &M);
    hashtable = (node*)malloc(sizeof(node) * M);
    for (i = 0; i < M; i++) {
        hashtable[i].value = 0;
        hashtable[i].next = NULL;
    }

    while (1) {
        scanf("%c", &ord);
        switch (ord) {
        case 'i':
            scanf("%d", &num);
            insert(hashtable, M, num);
            break;
        case 's':
            scanf("%d", &num);
            search(hashtable, M, num);
            break;
        case 'd':
            scanf("%d", &num);
            deletekey(hashtable, M, num);
            break;
        case 'p':
            printkey(hashtable, M);
            break;
        case 'e':
            free(hashtable);
            return 0;
        }
    }

    return 0;
}

int hashfunction(int x, int m) {
    return x % m;
}
void insert(node* hashtable, int size, int n) {
    int code = hashfunction(n, size);
    node* temp = (node*)malloc(sizeof(node));
    temp->value = n;
    temp->next = hashtable[code].next;
    hashtable[code].next = temp;

}
void search(node* hashtable, int size, int n) {
    int cnt = 0;
    int code = hashfunction(n, size);
    node* temp = hashtable[code].next;
    while (temp != NULL) {
        cnt++;
        if (temp->value == n) {
            printf("%d\n", cnt);
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("0\n");
    }

}
void deletekey(node* hashtable, int size, int n) {
    int code = hashfunction(n, size);
    int cnt = 0;
    node* temp = &hashtable[code];
    node* temp2;

    while (temp->next != NULL) {
        cnt++;
        if (temp->next->value == n) {
            temp2 = temp->next;
            temp->next = temp2->next;
            free(temp2);
            printf("%d\n", cnt);
            return;
        }
        temp = temp->next;
    }
    printf("0\n");
}
void printkey(node* hashtable, int size) {
    int i;
    node* temp;

    for (i = 0; i < size; i++) {
        temp = hashtable[i].next;
        while (temp != NULL) {
            if (temp->value != 0) {
                printf(" %d", temp->value);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}
