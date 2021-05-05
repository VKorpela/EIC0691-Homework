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
	int to;
	GNode *next;
} *AdjLink;

#define GRAPH_V_SIZE 100

struct Graph {
	int vsize, esize;
	AdjLink *node;
	bool *visit;
};

Status graphInit(Graph &G) {
	G.vsize = GRAPH_V_SIZE;
	G.esize = 0;
	G.node = (AdjLink*) malloc(GRAPH_V_SIZE * sizeof(AdjLink));
	G.visit = (bool*) malloc(GRAPH_V_SIZE * sizeof(bool));
	if (G.node == NULL || G.visit == NULL) return OVERFLOW;
	for (int i = 0; i < GRAPH_V_SIZE; i++) {
		G.node[i] = (GNode*) malloc(sizeof(GNode));
		if (G.node[i] == NULL) return OVERFLOW;
		G.node[i]->next = NULL;
		G.visit[i] = false;
	}
	return OK;
}

Status graphAddEdge(Graph &G, int vf, int vt) {
	if (vf >= G.vsize || vt >= G.vsize) return ERROR;
	GNode *p = (GNode*) malloc(sizeof(GNode));
	p->next = G.node[vf]->next;
	G.node[vf]->next = p;
	p->to = vt;
	G.esize++;
	return OK;
}

bool graphFindPath(Graph G, int vf, int vt) {
	queue<int> Q;
	Q.push(vf);
	while (!Q.empty()) {
		int vc = Q.front();
		Q.pop();
		if (G.visit[vc]) continue;
		else G.visit[vc] = true;
		if (vc == vt) return true;
		for (GNode *p = G.node[vc]->next; p != NULL; p = p->next)
			if (!G.visit[p->to]) Q.push(p->to);
	}
	return false;
}

int main() {
	Graph G;
	int e, v1, v2;
	graphInit(G);
	printf("Input the number of edges: \n");
	scanf("%d", &e);
	printf("Input the edges: \n");
	for (int i = 0; i < e; i++) {
		int f, t;
		scanf("%d%d", &f, &t);
		graphAddEdge(G, f, t);
	}
	printf("Input v_i and v_j: \n");
	scanf("%d%d", &v1, &v2);

	if (graphFindPath(G, v1, v2)) printf("PATH FOUND! \n");
	else printf("PATH NOT FOUND! \n");
	return 0;
}