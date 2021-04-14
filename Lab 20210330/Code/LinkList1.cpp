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

Status listFind(LinkList L, int k, int &res) {
	LNode *p = L;
	for (int i = 1; i <= k; i++) {
		p = p->next;
		if (p == NULL) return INFEASIBLE;
	}
	res = p->data;
	return OK;
}

int listLength(LinkList L) {
	LNode *p = L->next;
	int length = 0;
	while (p != NULL) {
		length++;
		p = p->next;
	}
	return length;
}

int main() {
	int n, a[100];
	LinkList L;
	printf("Input the number of elements: \n");
	scanf("%d", &n);
	printf("Input the elements: \n");
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	listMake(L, n, a);
	
	int length = listLength(L);
	if (length % 2) {
		int mid;
		listFind(L, length / 2 + 1, mid);
		printf("Midpoint is: %d\n", mid);
	}
	else printf("Midpoint not found: even length\n");
	return 0;
}

