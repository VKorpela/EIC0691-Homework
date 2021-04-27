#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <queue>

#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

using namespace std;

typedef struct TNode {
	int key;
	TNode *LC, *RC;
} *BiTree;

typedef struct LNode {
	int data;
	LNode *next, *prev;
} *LinkList;

Status treeAdd(BiTree &T, int a) {
	if (T == NULL) {
		T = (BiTree) malloc(sizeof(TNode));
		if (T == NULL) return OVERFLOW;
		T->key = a;
		T->LC = T->RC = NULL;
		return OK;
	}
	if (T->key > a) return treeAdd(T->LC, a);
	else if (T->key < a) return treeAdd(T->RC, a);
	else return OK; 
}

Status linkInit(LinkList &L) {
	L = (LNode*) malloc(sizeof(LNode));
	if (L == NULL) return OVERFLOW;
	L->next = L->prev = NULL;
	return OK;
}

Status linkAdd(LinkList &L, int a) {
	LNode *p = (LNode*) malloc(sizeof(LNode));
	if (p == NULL) return OVERFLOW;
	p->next = L->next;
	L->next = p;
	if (p->next != NULL) p->next->prev = p;
	p->prev = L;
	p->data = a;
	return OK;
}

Status tree2Link(BiTree T, LinkList L) {
	if (T == NULL) return OK;
	tree2Link(T->RC, L);
	linkAdd(L, T->key);
	tree2Link(T->LC, L);
	return OK;
}

Status linkPrint(LinkList L) {
	LNode *p = L->next;
	while(p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

int main() {
	int n;
	BiTree T = NULL;
	printf("Input the number of nodes: \n");
	scanf("%d", &n);
	printf("Input the nodes: \n");
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		treeAdd(T, a);
	}

	LinkList L;
	linkInit(L);
	tree2Link(T, L);

	printf("Result: \n");
	linkPrint(L);
	return 0;
}