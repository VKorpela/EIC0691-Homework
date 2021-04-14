# 第三章作业
> 班级：生科登峰1901班
>
> 姓名：吴思承

## 3.3
输出结果为：
```
stack
```

## 3.7
题目中没有给出具体数值，故用括号表示计算后的数值，作为一个整体入栈。
| 步骤 | 运算符栈（OPTR） | 操作数栈（OPND） | 输入字符 |
| --- | --- | --- | --- |
| 1 | # |  | <u>A</u>-B\*C/D+E↑F# |
| 2 | # | A | <u>-</u>B\*C/D+E↑F# |
| 3 | # - | A | <u>B</u>\*C/D+E↑F# |
| 4 | # - | A B | <u>\*</u>C/D+E↑F# |
| 5 | # - \* | A B | <u>C</u>/D+E↑F# |
| 6 | # - \* | A B C | <u>/</u>D+E↑F# |
| 7 | # - \* / | A B C | <u>D</u>+E↑F# |
| 8 | # - \* / | A B C D | <u>+</u>E↑F# |
| 9 | # - \* | A B (C/D) | <u>+</u>E↑F# |
| 10 | # - | A (C/D\*B) | <u>+</u>E↑F# |
| 11 | # - + | A (C/D\*B) | <u>E</u>↑F# |
| 12 | # - + | A (C/D\*B) E | <u>↑</u>F# |
| 13 | # - + ↑ | A (C/D\*B) E | <u>F</u># |
| 14 | # - + ↑ | A (C/D\*B) E F | # |
| 15 | # - + | A (C/D\*B) (E↑F) | # |
| 16 | # - | A (C/D\*B+E↑F) | # |
| 17 | # | (A-C/D\*B+E↑F) | # |

## 3.10
```c
void test(int &sum) {
	int x;
	sum = 0;
	scanf("%d", &x);
	while (x != 0) {
		sum += x;
		scanf("%d", &x);
	}
	printf("%d", sum);
	return;
}
```

## 3.12
输出结果为：
```
char
```

## 3.19
此处和3.21均直接使用C++的STL std::stack实现栈。
```c++
//using namespace std;
bool check(char *s) {
	stack<char> st;
	for (int i = 0; s[i]; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			st.push(s[i]);
		else if (s[i] == ')') {
			if (!st.empty() && st.top() == '(') st.pop();
			else return false;
		}
		else if (s[i] == ']') {
			if (!st.empty() && st.top() == '[') st.pop();
			else return false;
		}
		else if (s[i] == '}') {
			if (!st.empty() && st.top() == '{') st.pop();
			else return false;
		}
	}
	return st.empty();
}
```

## 3.21
```C++
//using namespace std;
int isOper(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

Status revPolishExpr(char *s) {
    stack<char> st;
    for (int i = 0; s[i]; i++) {
        if (isOper(s[i])) {
            while (!st.empty() && isOper(s[i]) <= isOper(st.top())) {
                printf("%c", st.top());
                st.pop();
            }
            st.push(s[i]);
        }
        else printf("%c", s[i]);
    }
    while (!st.empty()) {
        printf("%c", st.top());
        st.pop();
    }
    printf("\n");
    return OK;
}
```

## 3.28
```C
struct LNode {
    ElemType data;
    LNode *next;
};

struct queue {
	LNode *elem;
	int size;
};

Status queueInit(queue &q) {
	q.elem = (LNode*) malloc(sizeof(LNode));
	q.elem->next = q.elem;
	q.size = 0;
	return OK;
}

Status queuePush(queue &q, ElemType data) {
	LNode *p = (LNode*) malloc(sizeof(LNode));
	if (p == NULL) return OVERFLOW;
	q.size++;
	p->data = data;
	p->next = q.elem->next;
	q.elem->next = p;
	q.elem = p;
	return OK;
}

Status queuePop(queue &q, int &data) {
	if (q.size == 0) return ERROR;
	LNode *p = q.elem->next->next;
	q.elem->next->next = p->next;
	q.size--;
	data = p->data;
	if (p == q.elem) q.elem = q.elem->next;
	free(p);
	return OK;
}
```