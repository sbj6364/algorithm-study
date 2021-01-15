#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hashfunction(int, int);
void initHtable(int*, int);
void insert(int*, int, int);
void search(int*, int, int);

int main() {

    int M, N, num;
    char ord;
    int* H;

    scanf("%d %d", &M, &N);
    H = (int*)malloc(sizeof(int) * M);
    initHtable(H, M);

    while (1) {
        scanf("%c", &ord);
        switch (ord) {
        case 'i':
            scanf("%d", &num);
            insert(H, M, num);
            break;
        case 's':
            scanf("%d", &num);
            search(H, M, num);
            break;
        case 'e':
            free(H);
            return 0;
        }
    }

    return 0;
}

int hashfunction(int x, int m) {
    return x % m;
}
void initHtable(int* H, int M) {
    int i;
    for (i = 0; i < M; i++) {
        H[i] = 0;
    }
}
void insert(int* H, int M, int num) {

    int code = hashfunction(num, M);

    if (H[code] == 0) {
        H[code] = num;
        printf("%d\n", code);
    }
    else {
        while (H[code] != 0) {
            printf("C");
            code++;
            if (code == M) {
                code = 0;
            }
        }
        H[code] = num;
        printf("%d\n", code);
    }

}
void search(int* H, int M, int num) {

    int code = hashfunction(num, M);
    int cnt = 0;

    if (H[code] == num) {
        printf("%d %d\n", code, num);
    }
    else {
        while (H[code] != num) {
            cnt++;
            code++;
            if (code == M) {
                code = 0;
            }
            if (cnt == M) {
                printf("-1\n");
                return;
            }
        }
        printf("%d %d\n", code, num);
    }
}
