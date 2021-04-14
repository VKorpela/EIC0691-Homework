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
	int n, L1, L2;
	printf("Input the number of nodes: \n");
	scanf("%d", &n);
	printf("Input POSITION and NEXT of each node: \n");
	for (int i = 0; i < n; i++) {
		int p, nx;
		scanf("%d%d", &p, &nx);
		nxt[p] = nx;
	}
	printf("Input the head of linklist 1 & 2: \n");
	scanf("%d%d", &L1, &L2);
	
	int len1, len2;
	len1 = listLength(L1);
	len2 = listLength(L2);
	
	int i = L1, j = L2;
	while (len1 > len2) {
		i = nxt[i];
		len1--;
	}
	while (len1 < len2) {
		j = nxt[j];
		len2--;
	}
	while (i != j) {
		i = nxt[i];
		j = nxt[j];
	}
	
	if (i == -1) printf("No junction!\n");
	else printf("Junction at pos: %d\n", i);
	return 0;
}

