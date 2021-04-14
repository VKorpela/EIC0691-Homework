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

LinkList linkMerge(LinkList A, LinkList B) {
	LNode *p = A, *q = B->next;
	while (q != NULL) {
		while (p->next != NULL && p->next->data <= q->data)
			p = p->next;
		B->next = q->next;
		q->next = p->next;
		p->next = q;
		q = B->next;
	}
	free(B);
	return A;
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

int main() {
	int n, m, a[100], b[100];
	LinkList L1, L2;
	printf("Input the number of elements in A and B: \n");
	scanf("%d%d", &n, &m);
	printf("Input the elements of A: \n");
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("Input the elements of B: \n");
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);
	listMake(L1, n, a);
	listMake(L2, m, b);
	
	L1 = linkMerge(L1, L2);
	listReverse(L1);

	printf("Results: \n");
	listPrint(L1);
	return 0;
}

