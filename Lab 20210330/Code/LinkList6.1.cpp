#include <iostream>
#include <cstdlib>
#include <cstdio>

#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

using namespace std;

typedef struct LNode {
	int data;
	LNode *next;
} *LinkList;

Status listInit(LinkList &L) {
	L = (LNode *) malloc(sizeof(LNode));
	if (L == NULL) return OVERFLOW;
	L->next = NULL;
	return OK;
}

Status listInsert(LinkList &L, int data) {
	LNode *p = (LNode *) malloc(sizeof(LNode));
	if (p == NULL) return OVERFLOW;
	p->next = L->next;
	p->data = data;
	L->next = p;
	return OK;
}

Status listMake(LinkList &L, int n, int *a) {
	listInit(L);
	for (int i = n - 1; i >= 0; i--)
		if (listInsert(L, a[i]) == OVERFLOW)
			return OVERFLOW;
	return OK;
}

Status listPrint(LinkList L) {
	LNode *p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

Status listUnique(LinkList &L) {
	LNode *p = L->next;
	while(p->next != NULL) {
		if (p->data == p->next->data) {
			LNode *q = p->next;
			p->next = q->next;
			free(q);
		}
		else p = p->next;
	}
	return OK;
}

int main() {
	int n, a[100];
	LinkList L;
	printf("Input the number of elements: \n");
	scanf("%d", &n);
	printf("Input the elements: \n");
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	listMake(L, n, a);
	
	listUnique(L);
	
	printf("Results: \n");
	listPrint(L);
	return 0;
}

