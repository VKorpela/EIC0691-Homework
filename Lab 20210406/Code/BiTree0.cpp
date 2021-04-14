#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <stack>

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

Status DLR_NR(BiTree T) {
	stack<BiTree> S;
	S.push(T);
	while (!S.empty()) {
		BiTree cur = S.top();
		S.pop();
		printf("%d ", cur->tag);
		if (cur->RC != NULL) S.push(cur->RC);
		if (cur->LC != NULL) S.push(cur->LC);
	}
	printf("\n");
	return OK;
}

Status DLR(BiTree T) {
	printf("%d ", T->tag);
	if (T->LC != NULL) DLR(T->LC);
	if (T->RC != NULL) DLR(T->RC);
	return OK;
}

Status LDR(BiTree T) {
	if (T->LC != NULL) LDR(T->LC);
	printf("%d ", T->tag);
	if (T->RC != NULL) LDR(T->RC);
	return OK;
}

Status LRD(BiTree T) {
	if (T->LC != NULL) LRD(T->LC);
	if (T->RC != NULL) LRD(T->RC);
	printf("%d ", T->tag);
	return OK;
}

int main() {
	BiTree T = NULL;
	printf("Describe the binary tree: \n");
	T = treeBuild();
	
	printf("Non-recursive DLR traversal: \n");
	DLR_NR(T);
	
	printf("Recursive DLR traversal: \n");
	DLR(T);
	printf("\n");
	
	printf("Recursive LDR traversal: \n");
	LDR(T);
	printf("\n");
	
	printf("Recursive LRD traversal: \n");
	LRD(T);
	printf("\n");
	return 0;
}

