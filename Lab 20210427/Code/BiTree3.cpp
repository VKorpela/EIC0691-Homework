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

bool treeCheck(BiTree T) {
	bool flag = false;
	queue<BiTree> Q;
	Q.push(T);
	while (!Q.empty()) {
		BiTree cur = Q.front();
		Q.pop();
		if (flag) {
			if (cur->LC != NULL || cur->RC != NULL)
				return false;
		}
		else {
			if (cur->LC != NULL) {
				Q.push(cur->LC);
				if (cur->RC == NULL) flag = true;
				else Q.push(cur->RC);
			}
			else if (cur->RC != NULL) return false;
			else flag = true;
		}
	}
	return true;
}

int main() {
	BiTree T = NULL;
	printf("Describe the binary tree: \n");
	T = treeBuild();
	
	if (treeCheck(T)) printf("IS COMPLETE!\n");
	else printf("NOT COMPLETE!\n");
	return 0;
}