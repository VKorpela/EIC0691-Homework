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

int getMaxPath(BiTree T, int &maxl) {
	if (T == NULL) return 0;
	int lenL, lenR;
	lenL = getMaxPath(T->LC, maxl);
	lenR = getMaxPath(T->RC, maxl);
	maxl = max(maxl, lenL + lenR);
	return max(lenL, lenR) + 1;
}

int main() {
	BiTree T = NULL;
	printf("Describe the binary tree: \n");
	T = treeBuild();
	
	int ans = -1;
	getMaxPath(T, ans);

	printf("Result: %d\n", ans);
	return 0;
}

