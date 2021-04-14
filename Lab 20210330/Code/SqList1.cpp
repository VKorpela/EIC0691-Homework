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

Status listDelete(SqList &L, int pos) {
	if (pos >= L.length || pos < 0) return ERROR;
	for (int i = pos + 1; i < L.length; i++)
		L.elem[i - 1] = L.elem[i];
	L.length--;
	return OK;
}

int main() {
	int n;
	SqList L;
	listInit(L);
	printf("Input the number of elements: \n");
	scanf("%d", &n);
	printf("Input the elements: \n");
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		listInsert(L, tmp);
	}
	
	int i = 0;
	while (i < L.length) {
		if (L.elem[i] == 0)
			listDelete(L, i);
		else i++;
	}
	
	printf("Results: \n");
	for (int i = 0; i < L.length; i++)
		printf("%d ", L.elem[i]);
	printf("\n");	
	return 0;
}
