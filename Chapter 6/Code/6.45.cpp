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

Status treeNodeDelete(BiTree T) {
    if (T->LC != NULL) treeNodeDelete(T->LC);
    if (T->RC != NULL) treeNodeDelete(T->RC);
    free(T);
    return OK;
}

bool treeDelete(BiTree T, int x) {
    if (T->tag == x) {
        treeNodeDelete(T);
        return true;
    }
    if (T->LC != NULL && treeDelete(T->LC, x)) T->LC = NULL;
    if (T->RC != NULL && treeDelete(T->RC, x)) T->RC = NULL;
    return false;
}

int main() {
    int x;
    BiTree T = NULL;
    printf("Describe the binary tree: \n");
    T = treeBuild();
    printf("Input x: \n");
    scanf("%d", &x);
    
    if (treeDelete(T, x)) T = NULL;

    printf("Result: \n");
    treePrint(T);
    printf("\n");
    return 0;
}

