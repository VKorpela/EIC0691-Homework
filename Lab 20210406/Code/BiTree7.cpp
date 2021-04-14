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

Status LDR_NR(BiTree T) {
	stack<BiTree> S_cur, S_pre;
	S_cur.push(T);
	while (!S_cur.empty()) {
		BiTree cur = S_cur.top();
		S_cur.pop();
		if (S_pre.empty() || S_pre.top() != cur) {
			S_pre.push(cur);
			if (cur->RC != NULL) S_cur.push(cur->RC);
			S_cur.push(cur);
			if (cur->LC != NULL) S_cur.push(cur->LC);
		}
		else {
			S_pre.pop();
			printf("%d ", cur->tag);
		}
	}
	printf("\n");
	return OK;
}

Status LRD_NR(BiTree T) {
	stack<BiTree> S_cur, S_pre;
	S_cur.push(T);
	while (!S_cur.empty()) {
		BiTree cur = S_cur.top();
		S_cur.pop();
		if (S_pre.empty() || S_pre.top() != cur) {
			S_pre.push(cur);
			S_cur.push(cur);
			if (cur->RC != NULL) S_cur.push(cur->RC);
			if (cur->LC != NULL) S_cur.push(cur->LC);
		}
		else {
			S_pre.pop();
			printf("%d ", cur->tag);
		}
	}
	printf("\n");
	return OK;
}

int main() {
	BiTree T = NULL;
	printf("Describe the binary tree: \n");
	T = treeBuild();
	
	printf("Non-recursive LDR traversal: \n");
	LDR_NR(T);
	printf("Non-recursive LRD traversal: \n");
	LRD_NR(T);
	return 0;
}

