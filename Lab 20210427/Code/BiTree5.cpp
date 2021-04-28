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
	int tag, depth;
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

bool treeIsBalance(BiTree T) {
	int depL, depR;
	if (T->LC != NULL) {
		if (!treeIsBalance(T->LC)) return false;
		depL = T->LC->depth;
	}
	else depL = 0;
	if (T->RC != NULL) {
		if (!treeIsBalance(T->RC)) return false;
		depR = T->RC->depth;
	}
	else depR = 0;
	T->depth = max(depL, depR) + 1;
	if (depL - depR > 1 || depL - depR < -1) return false;
	else return true;
}

int main() {
	BiTree T = NULL;
	printf("Describe the binary tree: \n");
	T = treeBuild();
	
	if (treeIsBalance(T)) printf("IS BALANCED!\n");
	else printf("NOT BALANCED!\n");
	return 0;
}

