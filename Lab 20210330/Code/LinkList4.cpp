#include <iostream>
#include <cstdlib>
#include <cstdio>

#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

using namespace std;

int nxt[100];

int listLength(int L) {
	int p = L;
	int length = 0;
	while (p != -1) {
		length++;
		p = nxt[p];
	}
	return length;
}

int main() {
	int n, L;
	printf("Input the number of nodes: \n");
	scanf("%d", &n);
	printf("Input POSITION and NEXT of each node: \n");
	for (int i = 0; i < n; i++) {
		int p, nx;
		scanf("%d%d", &p, &nx);
		nxt[p] = nx;
	}
	printf("Input the head of linklist: \n");
	scanf("%d", &L);
	
	int i, j;
	bool flag = false;
	i = j = L;

	while(j != -1) {
		i = nxt[i];
		if (nxt[j] != -1) j = nxt[nxt[j]];
		else break;
		if (i == j) {
			flag = true;
			break;
		}
	}

	if (flag) {
		i = L;
		while (i != j) {
			i = nxt[i];
			j = nxt[j];
		}
		printf("Loop starting from: %d\n", i);
	}
	else printf("LOOP NOT FOUND!\n");
	return 0;
}

