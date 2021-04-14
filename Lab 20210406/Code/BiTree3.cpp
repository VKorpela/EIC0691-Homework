#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

using namespace std;

typedef struct TNode {
	char tag;
	TNode *LC, *RC;
} *BiTree;

BiTree treeBuild(char *DLR, char *LDR) {
	int len = strlen(DLR);
	if (len == 0) return NULL;
	BiTree p = (BiTree) malloc(sizeof(TNode));
	p->tag = DLR[0];
	char LC_DLR[100], LC_LDR[100], RC_DLR[100], RC_LDR[100];
	int i = 1, j = 0, k = 0;
	while (i <= len && j <= len) {
		if (LDR[j] == p->tag) {
			j++;
			LC_DLR[k] = LC_LDR[k] = 0;
			k = 0;
			break;
		}
		LC_DLR[k] = DLR[i];
		LC_LDR[k] = LDR[j];
		i++; j++; k++;
	}
	while (i <= len && j <= len) {
		RC_DLR[k] = DLR[i];
		RC_LDR[k] = LDR[j];
		i++; j++; k++;
	}
	p->LC = treeBuild(LC_DLR, LC_LDR);
	p->RC = treeBuild(RC_DLR, RC_LDR);
	return p;
}

Status treePrint(BiTree T) {
	if (T == NULL) {
		printf("^ ");
		return OK;
	}
	printf("%c ", T->tag);
	treePrint(T->LC);
	treePrint(T->RC);
	return OK;
}

int main() {
	char DLR[100], LDR[100];
	BiTree T = NULL;
	printf("Input DLR traversal and LDR traversal of the tree: \n");
	scanf("%s%s", DLR, LDR);
	
	T = treeBuild(DLR, LDR);
	
	printf("Result: \n");
	treePrint(T);
	printf("\n");
	return 0;
}

