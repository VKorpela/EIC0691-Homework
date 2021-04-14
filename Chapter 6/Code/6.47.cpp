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

Status BFS(BiTree T) {
    queue<BiTree> Q;
    Q.push(T);
    while (!Q.empty()) {
        BiTree cur = Q.front();
        Q.pop();
        printf("%d ", cur->tag);
        if (cur->LC != NULL) Q.push(cur->LC);
        if (cur->RC != NULL) Q.push(cur->RC);
    }
    printf("\n");
    return OK;
}


int main() {
    BiTree T = NULL;
    printf("Describe the binary tree: \n");
    T = treeBuild();
    
    printf("Result: \n");
    BFS(T);
    return 0;
}

