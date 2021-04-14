#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

using namespace std;

typedef struct TNode {
	int tag;
	TNode *LC, *RC;
} *BiTree;

BiTree treeBuild() {
	int id;
	scanf("%d", &id);
	if (id == 0) return NULL;
	BiTree p = (BiTree) malloc(sizeof(TNode));
	p->tag = id;
	p->LC = treeBuild();
	p->RC = treeBuild();
	return p;
}

int treeCount(BiTree T, int k) {
	if (T == NULL) return 0;
	if (k == 1) return 1;
	return treeCount(T->LC, k - 1) + treeCount(T->RC, k - 1);
}

int main() {
	int k;
	BiTree T = NULL;
	printf("Describe the binary tree: \n");
	T = treeBuild();
	printf("Input number K: \n");
	scanf("%d", &k);
	
	printf("Result: %d\n", treeCount(T, k));
	return 0;
}

