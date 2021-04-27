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

Status treeBuild(BiTree &T) {
	stack<BiTree*> S;
	S.push(&T);
	while(!S.empty()) {
		BiTree *cur = S.top();
		S.pop();
		int id;
		scanf("%d", &id);
		if (id == 0) *cur = NULL;
		else {
			*cur = (BiTree) malloc(sizeof(TNode));
			(*cur)->tag = id;
			S.push(&(*cur)->RC);
			S.push(&(*cur)->LC);
		}
	}
	return OK;
}

Status treePrint(BiTree T) {
	if (T == NULL) {
		printf("^ ");
		return OK;
	}
	printf("%d ", T->tag);
	treePrint(T->LC);
	treePrint(T->RC);
	return OK;
}

int main() {
	BiTree T = NULL;
	printf("Describe the binary tree: \n");
	treeBuild(T);

	printf("Result: \n");
	treePrint(T);
	printf("\n");
	return 0;
}