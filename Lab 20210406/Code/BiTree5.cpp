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

int BiTree[100];

Status treeBuild(int t) {
	int id;
	scanf("%d", &id);
	BiTree[t] = id;
	if (id == 0) return OK;
	treeBuild(t * 2);
	treeBuild(t * 2 + 1);
	return OK;
}

Status treeWidth() {
	int cnt = 0, dep = 1, maxw = -1;
	bool flag = true;
	for (int i = 1; i < 1 << dep || flag; i++) {
		if (i == 1 << dep) {
			dep++;
			cnt = 0;
			flag = false;
		}
		if (BiTree[i] == 0) continue;
		if (BiTree[i * 2] || BiTree[i * 2 + 1]) flag = true;
		cnt++;
		maxw = max(maxw, cnt);
	}
	return maxw;
}

int main() {
	printf("Describe the binary tree: \n");
	treeBuild(1);
	
	printf("Result: %d\n", treeWidth());
	return 0;
}

