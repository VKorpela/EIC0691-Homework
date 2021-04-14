#include <iostream>
#include <cstdlib>
#include <cstdio>

#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

using namespace std;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

struct SqList {
	int *elem;
	int length;
	int listsize;
};

Status listInit(SqList &L) {
	L.elem = (int *) malloc(LIST_INIT_SIZE * sizeof(int));
	if (L.elem == NULL) return OVERFLOW;
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

Status listInsert(SqList &L, int data) {
	if (L.length == L.listsize) {
		L.listsize += LISTINCREMENT;
		L.elem = (int *) realloc(L.elem, L.listsize * sizeof(int));
		if (L.elem == NULL) return OVERFLOW;
	}
	L.elem[L.length++] = data;
	return OK;
}

Status makeNext(SqList T, SqList &N) {
	listInsert(N, -1);
	int i = 1, j = -1;
	while (i < T.length) {
		if (j == -1 || T.elem[i] == T.elem[j]) {
			i++; j++;
			listInsert(N, j);
		}
		else j = N.elem[j];
	}
	return OK;
}

int KMP(SqList A, SqList B, int pos = 0) {
	SqList N;
	listInit(N);
	makeNext(B, N);
	int i = pos, j = 0;
	while (i < A.length) {
		if (A.elem[i] == B.elem[j]) i++, j++;
		else j = N.elem[j];
		if (j == B.length) return i - B.length;
		if (j == -1) i++, j++;
	}
	return -1;
}

int main() {
	int n;
	SqList A, B;
	listInit(A);
	listInit(B);
	
	printf("Input the number of elements in A: \n");
	scanf("%d", &n);
	printf("Input the elements in A: \n");
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		listInsert(A, tmp);
	}
	
	printf("Input the number of elements in B: \n");
	scanf("%d", &n);
	printf("Input the elements in B: \n");
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		listInsert(B, tmp);
	}
	
	int res = KMP(A, B, 0);
	if (res != -1) printf("First B found in A at: %d\n", res);
	else printf("B not found in A\n");
	return 0;
}
