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

Status listMake(LinkList &L, int n) {
	listInit(L);
	LNode *p = L;
	for (int i = 1; i <= n; i++) {
		LNode *q = (LNode*) malloc(sizeof(LNode));
		if (q == NULL) return OVERFLOW;
		p->next = q;
		q->next = L->next;
		q->data = i;
		p = q;
	}
	return OK;
}

int main() {
	int n, m;
	LinkList L;
	printf("Input number n and m: \n");
	scanf("%d%d", &n, &m);
	listMake(L, n);
	
	printf("Results: \n");
	LNode *p = L;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < m; j++) p = p->next;
		printf ("%d OUT\n", p->next->data);
		LNode *q = p->next;
		if (p->next != p) p->next = q->next;
		else L->next = NULL;
		free(q);
	}
	return 0;
}

