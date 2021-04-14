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

int BiTree[100], Depth[100];

Status treeBuild(int t) {
	int id;
	scanf("%d", &id);
	BiTree[t] = id;
	if (id == 0) return OK;
	Depth[t] = Depth[t >> 1] + 1;
	treeBuild(t * 2);
	treeBuild(t * 2 + 1);
	return OK;
}

int treeFind(int tag) {
	for (int i = 1; i < 100; i++) 
		if (BiTree[i] == tag) return i;
	return -1;
}

int LCA(int A, int B) {
	int Apos = treeFind(A), Bpos = treeFind(B);
	while (Depth[Apos] != Depth[Bpos]) {
		if (Depth[Apos] > Depth[Bpos]) Apos /= 2;
		else Bpos /= 2;
	}
	while (Apos != Bpos) {
		Apos /= 2;
		Bpos /= 2;
	}
	return BiTree[Apos];
}

int main() {
	int A, B;
	printf("Describe the binary tree: \n");
	treeBuild(1);
	printf("Input A and B: \n");
	scanf("%d%d", &A, &B);
	
	printf("LCA of A and B is: %d\n", LCA(A, B));
	return 0;
}

