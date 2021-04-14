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

Status bubbleSort(SqList &L) {
	for (int i = 0; i < L.length - 1; i++) {
		bool flag = false;
		for (int j = 0; j < L.length - i - 1; j++) {
			if (L.elem[j] > L.elem[j + 1]) {
				int tmp = L.elem[j + 1];
				L.elem[j + 1] = L.elem[j];
				L.elem[j] = tmp;
				flag = true;
			}
		}
		if (!flag) break;
	}
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
	
	bubbleSort(L);
	
	printf("Results: \n");
	for (int i = 0; i < L.length; i++)
		printf("%d ", L.elem[i]);
	printf("\n");	
	return 0;
}
