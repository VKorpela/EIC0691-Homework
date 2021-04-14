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

Status treeInverse(BiTree T) {
    if (T->LC != NULL) treeInverse(T->LC);
    if (T->RC != NULL) treeInverse(T->RC);
    BiTree tmp = T->LC;
    T->LC = T->RC;
    T->RC = tmp;
    return OK;
}

int main() {
    BiTree T = NULL;
    printf("Describe the binary tree: \n");
    T = treeBuild();
    
    treeInverse(T);
    
    printf("Result: \n");
    treePrint(T);
    printf("\n");
    return 0;
}

