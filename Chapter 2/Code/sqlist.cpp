#include <iostream>
#include <cstdlib>
#include <cstdio>
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

using namespace std;

typedef int Status;

typedef struct {
    int *elem;
    int length;
    int listsize;
} SqList;

Status listInit(SqList &L) {
    L.elem = (int *) malloc(LIST_INIT_SIZE * sizeof(int));
    if (L.elem == NULL) return OVERFLOW;
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

Status listInsert(SqList &L, int data) {
    if (L.length == L.listsize) {
        L.elem = (int *) realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(int));
        if (L.elem == NULL) return OVERFLOW;
        L.listsize += LISTINCREMENT;
    }
    L.elem[L.length] = data;
    L.length++;
    return OK;
}

SqList makeList(int *a, int n) {
    SqList L;
    listInit(L);
    for (int i = 0; i < n; i++) listInsert(L, a[i]);
    return L;
}

Status printList(SqList L) {
    for (int i = 0; i < L.length; i++) printf("%d ", L.elem[i]);
    printf("\n");
    return OK;
}

Status listReverse(SqList &L) {
    for (int i = 0, j = L.length - 1; i < j; i++, j--) {
        int tmp = L.elem[i];
        L.elem[i] = L.elem[j];
        L.elem[j] = tmp;
    }
    return OK;
}

Status compDelete(SqList &A, SqList B, SqList C) {
    int i, j, k;
    i = j = k = 0;
    while (i != A.length) {
        while (j != B.length && B.elem[j] < A.elem[i]) j++;
        while (k != C.length && C.elem[k] < A.elem[i]) k++;
        if (j == B.length || k == C.length) break;
        else if (A.elem[i] == B.elem[j] && A.elem[i] == C.elem[k]) {
            for (int t = i; t < A.length - 1; t++)
                A.elem[t] = A.elem[t+1];
            A.length--;
        }
        else i++;
    }
    return OK;
}

int main() {
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[5] = {1, 1, 4, 5, 14};
    int c[4] = {1, 9, 19, 810};
    SqList A = makeList(a, 10);
    SqList B = makeList(b, 5);
    SqList C = makeList(c, 4);
    printList(A);
    listReverse(A);
    printList(A);
    listReverse(A);
    printList(A);
    printList(B);
    printList(C);
    compDelete(A, B, C);
    printList(A);
    return 0;
}