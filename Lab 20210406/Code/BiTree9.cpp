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

int leafCount(BiTree T) {
	if (T == NULL) return 0;
	if (T->LC == NULL && T->RC == NULL) return 1;
	return leafCount(T->LC) + leafCount(T->RC);
}

int main() {
	BiTree T = NULL;
	printf("Describe the binary tree: \n");
	T = treeBuild();
	
	printf("Result: %d\n", leafCount(T));
	return 0;
}

