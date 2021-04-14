#include <iostream>
#include <cstdlib>
#include <cstdio>
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

using namespace std;

typedef int Status;

typedef struct LNode {
    int data;
    LNode *next;
} *LinkList;

LinkList linkInit() {
    LinkList L = (LNode*) malloc(sizeof(LNode));
    L->data = 0; L->next = NULL;
    return L;
}

Status linkInsert(LNode *p, int data) {
    LNode *n = (LNode*) malloc(sizeof(LNode));
    if (n == NULL) return OVERFLOW;
    n->data = data;
    n->next = p->next;
    p->next = n;
    return OK;
}

LinkList makeLink(int *a, int n) {
    LinkList L = linkInit();
    for (int i = n-1; i >= 0; i--)
        linkInsert(L, a[i]);
    return L;
}

Status printLink(LinkList L) {
    LNode *p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

Status linkReverse1(LinkList L) {
    if (L->next == NULL) return INFEASIBLE;	//空链表无法执行逆置
    LNode *p = L;
    while (p->next != NULL) p = p->next;	//找到链表末尾，记为p
    while (L->next != p) {					//若首元结点为p则链表逆置完成
        LNode *q = L->next;					//用q暂存首元结点的地址
        L->next = q->next;					//将q从链表头部移除
        q->next = p->next;
        p->next = q;						//将q重新插入到p后
    }
    return OK;
}

Status linkReverse2(LinkList L) {
    LinkList _L = NULL;				//新建一个没有头节点的空链表_L
    while(L->next != NULL) {		//当L中没有结点时逆置完成
        LNode *q = L->next;			//用q暂存首元节点的地址		
        L->next = q->next;			//将q从链表头部移除
        q->next = _L;
        _L = q;						//将q插入到_L的最前面
    }
    L->next = _L;					//将_L整体插入到L的头节点后面
    return OK;
}

LinkList linkMerge(LinkList A, LinkList B) {
    LNode *p = A, *q = B->next;
    while (q != NULL) {			//每次循环都将B的首元节点q插入到A的合适位置中
        while (p->next != NULL && p->next->data <= q->data)
            p = p->next;		//寻找合适的插入q的位置
        B->next = q->next;		//将q从链表B中删去
        q->next = p->next;
        p->next = q;			//将q插入到p后面
        q = B->next;			//准备插入B中的下一个结点
    }
    free(B);					//释放B的头节点
    return A;					//A即为合并完毕的链表
}

Status rangeDelete(LinkList L, int mink, int maxk) {
    LNode *p = L;
    while (p->next != NULL && p->next->data <= mink) p = p->next;
    while (p->next != NULL && p->next->data < maxk) {
        LNode *q = p->next;
        p->next = q->next;
        free(q);
    }
    return OK;
}

Status compDelete(LinkList A, LinkList B, LinkList C) {
    LNode *i = A, *j = B->next, *k = C->next;
    while (i->next != NULL) {
        while (j != NULL && j->data < i->next->data) j = j->next;
        while (k != NULL && k->data < i->next->data) k = k->next;
        if (j == NULL || k == NULL) break;
        else if (i->next->data == j->data && i->next->data == k->data) {
            LNode *t = i->next;
            i->next = t->next;
            free(t);
        }
        else i = i->next;
    }
    return OK;
}

int main() {
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[5] = {1, 1, 4, 5, 14};
    int c[4] = {1, 9, 19, 810};
    LinkList L1 = makeLink(a, 10);
    LinkList L2 = makeLink(b, 5);
    LinkList L3 = makeLink(c, 4);
    printLink(L1);
    linkReverse1(L1);
    printLink(L1);
    linkReverse2(L1);
    printLink(L1);
    printLink(L2);
    printLink(L3);
    compDelete(L1, L2, L3);
    printLink(L1);
    printLink(L2);
    linkMerge(L1, L2);
    printLink(L1);
    rangeDelete(L1, 1, 9);
    printLink(L1);
    rangeDelete(L1, 8, 10);
    printLink(L1);
    return 0;
}