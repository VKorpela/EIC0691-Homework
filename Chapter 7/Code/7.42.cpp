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

typedef struct GNode {
	int to, weight;
	GNode *next;
} *AdjLink;

struct Graph {
	int vsize, esize;
	AdjLink *node;
	bool *visit;
};

Status graphInit(Graph &G, int size) {
	G.vsize = size;
	G.esize = 0;
	G.node = (AdjLink*) malloc(size * sizeof(AdjLink));
	G.visit = (bool*) malloc(size * sizeof(bool));
	if (G.node == NULL || G.visit == NULL) return OVERFLOW;
	for (int i = 0; i < size; i++) {
		G.node[i] = (GNode*) malloc(sizeof(GNode));
		if (G.node[i] == NULL) return OVERFLOW;
		G.node[i]->next = NULL;
		G.visit[i] = false;
	}
	return OK;
}

Status graphAddEdge(Graph &G, int vf, int vt, int w) {
	if (vf >= G.vsize || vt >= G.vsize) return ERROR;
	GNode *p = (GNode*) malloc(sizeof(GNode));
	p->next = G.node[vf]->next;
	G.node[vf]->next = p;
	p->to = vt;
	p->weight = w;
	G.esize++;
	return OK;
}

#define INF ~0u>>1

Status graphDijkstra(Graph G, int vs, int* result) {
	for (int i = 0; i < G.vsize; i++) result[i] = INF;
	result[vs] = 0;
	for (int i = 0; i < G.vsize; i++) {
		int vc = -1, dmin = INF;
		for (int j = 0; j < G.vsize; j++) {
			if (G.visit[j]) continue;
			if (result[j] < dmin) {
				dmin = result[j];
				vc = j;
			}
		}
		if (dmin == INF) break;
		G.visit[vc] = true;
		for (GNode *p = G.node[vc]->next; p != NULL; p = p->next)
			result[p->to] = min(result[p->to], result[vc] + p->weight);
	}
	return OK;
}

int main() {
	Graph G;
	int n, e, vs;
	printf("Input the number of nodes and edges: \n");
	scanf("%d%d", &n, &e);
	graphInit(G, n);
	printf("Input the edges: \n");
	for (int i = 0; i < e; i++) {
		int f, t, w;
		scanf("%d%d%d", &f, &t, &w);
		graphAddEdge(G, f, t, w);
	}
	printf("Input the starting point: \n");
	scanf("%d", &vs);

	int *res = (int*) malloc(n * sizeof(int));
	graphDijkstra(G, vs, res);

	printf("Result: \n");
	for (int i = 0; i < n; i++) 
		printf("%d ", res[i]);
	printf("\n");
	return 0;
}