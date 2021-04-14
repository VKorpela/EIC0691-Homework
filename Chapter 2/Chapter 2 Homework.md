# 第二章作业
> 班级：生科登峰1901班
>
> 姓名：吴思承

## 2.6
1. 在P结点后插入S结点的语句序列是 (4) (1)；
2. 在P结点前插入S结点的语句序列是 (7) (11) (8) (4) (1)；
3. 在表首插入S结点的语句序列是 (5) (12)；
4. 在表尾插入S结点的语句序列是 (11) (9) (1) (6)。

## 2.7
1. 删除P结点的直接后继结点的语句序列是 (11) (3) (14)；
2. 删除P结点的直接前驱结点的语句序列是 (10) (12) (8) (11) (3) (14)；
3. 删除P结点的语句序列是 (10) (12) (7) (11) (3) (14)；
4. 删除首元结点的语句序列是 (12) (11) (3) (14)；
5. 删除尾元结点的语句序列是 (12) (9) (11) (3) (14)。

## 2.9
1. 将链表的第一个结点移动到链表末尾处
2. AA函数将循环链表拆分为两部分：
   - pa到pb的前驱结点
   - pb到pa的前驱结点

## 2.19
```C
Status rangeDelete(LinkList L, ElemType mink, ElemType maxk) {
	LNode *p = L;
	while (p->next != NULL && p->next->data <= mink) p = p->next;
	while (p->next != NULL && p->next->data < maxk) {
		LNode *q = p->next;
		p->next = q->next;
		free(q);
	}
	return OK;
}
```
若链表的结点数为$n$，则算法的时间复杂度为$O(n)$。

## 2.21
```C
Status listReverse(SqList &L) {
	for (int i = 0, j = L.length - 1; i < j; i++, j--) {
		ElemType tmp = L.elem[i];
		L.elem[i] = L.elem[j];
		L.elem[j] = tmp;
	}
	return OK;
}
```

## 2.24
```C
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
```

## 2.29
```C
Status compDelete(SqList &A, SqList B, SqList C) {
	int i, j, k;
	i = j = k = 0;
	while (i != A.length) {
		while (j != B.length && B.elem[j] < A.elem[i]) j++;
		while (k != C.length && C.elem[k] < A.elem[i]) k++;
		if (j == B.length || k == C.length) break;
		else if (A.elem[i] == B.elem[j] && A.elem[i] == C.elem[k]) {
			for (int t = i; t < A.length - 1; t++)
				A.elem[t] = A.elem[t+1];
			A.length--;
		}
		else i++;
	}
	return OK;
}
```
若A的元素数量为$n$，则算法的时间复杂度为$O(n^2)$。

## 2.30
```C
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
```

## 补充练习题（即2.22）
### 方法1
```C
Status linkReverse(LinkList L) {
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
```

### 方法2
```C
Status linkReverse(LinkList L) {
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
```