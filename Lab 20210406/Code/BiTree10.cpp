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

bool treeCmp(BiTree T1, BiTree T2) {
	if (T1 == NULL && T2 == NULL) return true;
	if (T1 == NULL || T2 == NULL) return false;
	return treeCmp(T1->LC, T2->LC) && treeCmp(T1->RC, T2->RC);
}

int main() {
	BiTree T1 = NULL, T2 = NULL;
	printf("Describe the binary tree 1: \n");
	T1 = treeBuild();
	printf("Describe the binary tree 2: \n");
	T2 = treeBuild();
	
	if (treeCmp(T1, T2)) printf("SAME STRUCTURE\n");
	else printf("DIFFERENT STRUCTURE\n");
	return 0;
}

