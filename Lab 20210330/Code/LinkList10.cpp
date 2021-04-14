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

Status listReverse(LinkList &L) {
	LNode *p = L;
	while (p->next != NULL) p = p->next;
	while (L->next != p) {
		LNode *q = L->next;
		L->next = q->next;
		q->next = p->next;
		p->next = q;
	}
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

bool listCheck(LinkList L1, LinkList L2) {
	LNode *p = L1->next, *q = L2->next;
	while (p != NULL && q != NULL) {
		if (p->data != q->data) return false;
		p = p->next;
		q = q->next;
	}
	return true;
}

int main() {
	int n, a[100];
	LinkList L, M;
	printf("Input the number of elements: \n");
	scanf("%d", &n);
	printf("Input the elements: \n");
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	listMake(L, n, a);
	listInit(M);

	for (LNode *p = L->next; p != NULL; p = p->next)
		listInsert(M, p->data);

	if (listCheck(L, M)) printf("IS SYMMETRIC\n");
	else printf("NOT SYMMETRIC\n");
	return 0;
}

