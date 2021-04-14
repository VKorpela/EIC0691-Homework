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

Status treePrint(BiTree T) {
    if (T == NULL) {
        printf("^ ");
        return OK;
    }
    printf("%d ", T->tag);
    treePrint(T->LC);
    treePrint(T->RC);
    return OK;
}

int treeDepth(BiTree T) {
    if (T == NULL) return 0;
    return max(treeDepth(T->LC), treeDepth(T->RC)) + 1;
}

Status treeSearch(BiTree T, int x) {
    if (T->tag == x)
        printf("Depth of subtree is: %d\n", treeDepth(T));
    if (T->LC != NULL) treeSearch(T->LC, x);
    if (T->RC != NULL) treeSearch(T->RC, x);
    return OK;
}

int main() {
    int x;
    BiTree T = NULL;
    printf("Describe the binary tree: \n");
    T = treeBuild();
    printf("Input x: \n");
    scanf("%d", &x);

    printf("Result: \n");
    treeSearch(T, x);
    return 0;
}

