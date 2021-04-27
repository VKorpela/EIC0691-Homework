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
	int key, count;
	TNode *LC, *RC;
} *BiTree;

Status treeAdd(BiTree &T, int a) {
	if (T == NULL) {
		T = (BiTree) malloc(sizeof(TNode));
		if (T == NULL) return OVERFLOW;
		T->key = a;
		T->count = 1;
		T->LC = T->RC = NULL;
		return OK;
	}
	if (T->key > a) return treeAdd(T->LC, a);
	else if (T->key < a) return treeAdd(T->RC, a);
	else {
		T->count++;
		return OK;
	}
}

Status treeFind(BiTree T, int &maxk, int &maxc) {
	if (T == NULL) return OK;
	if (T->count > maxc) {
		maxc = T->count;
		maxk = T->key;
	}
	treeFind(T->LC, maxk, maxc);
	treeFind(T->RC, maxk, maxc);
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

	int ans, freq = -1;
	treeFind(T, ans, freq);

	printf("Result: %d\n", ans);
	return 0;
}