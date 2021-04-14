# 第一章作业
> 班级：生科登峰1901班
>
> 姓名：吴思承

## 1.6
1. 使用exit语句终止执行
   -  优点：在于可以当即结束出现错误的进程，在出现致命错误时可以避免程序继续运行产生更严重的问题。
   -  缺点：对于一些不严重的问题，往往可以在程序/进程内纠正，但直接终止进程时无法进行此类纠正。此外，在发生错误时直接使用exit语句也不利于调试。
2. 用函数返回值区别
   - 优点：可以在不终止程序的情况下尝试通过异常的返回值判断错误，并在程序内修正问题。
   - 缺点：需要事前约定与错误对应的特殊函数返回值，且函数的正常返回值不能与代表错误的返回值冲突。
3. 设置一个整型变量的函数参数以区别正常返回或错误返回
   - 优点：不会终止程序，专门表示状态的变量也可以避免“2.”中的方法中潜在的冲突。
   - 缺点：每次调用函数都需要开辟内存来接收函数运行状态，对于大量递归的函数可能会造成内存的浪费。

## 1.7
1. scanf/printf函数
   - 优点：可以直接从用户处获取信息，或将信息输出给用户。
   - 缺点：只能与键盘/屏幕/文件交互，并不能在函数之间传递信息。
2. 函数参数显式传递
   - 优点：可以在函数之间传递信息。作用域仅限于传递给的函数，稳定安全。临时变量的内存可以动态地开辟和释放。
   - 缺点：每次调用函数都需要重新传递一次。如果以临时变量的形式传递则无法对变量的原始值进行修改。
3. 全局变量隐式传递
   - 优点：可以在函数之间传递信息。变量作用域为整个程序，不需要专门的参数。一个变量可以被多个函数调用并修改。
   - 缺点：过多的全局变量可能会占用大量内存，变量名也相对难以管理。

## 1.8
1. $f(n)=n-1$
2. $f(n)=n-2$
3. $f(n)=n-1$
4. $f(n)=\sum\limits^n_{i=1}i=\frac{n^2}{2}+\frac{n}{2}$
5. $f(n)=\sum\limits^n_{i=1}\frac{1}{2}i(i+1)=\frac{n^3}{6}+\frac{n^2}{2}+\frac{n}{3}$
6. n为偶数时：$f(n)=\frac{n}{2}$
   n为奇数时：$f(n)=\frac{n+1}{2}$
7. $f(n)=\lfloor\sqrt{n}\rfloor$（向下取整）
8. $f(n)=100$



## 1.16
``` C
Status sort3() {
	int X, Y, Z;
	scanf("%d%d%d", &X, &Y, &Z);
	if (X > Y) {
		if (Y > Z) printf("%d %d %d", X, Y, Z);
		else if (X > Z) printf("%d %d %d", X, Z, Y);
		else printf("%d %d %d", Z, X, Y);
	}
	else {
		if (X > Z) printf("%d %d %d", Y, X, Z);
		else if (Y > Z) printf("%d %d %d", Y, Z, X);
		else printf("%d %d %d", Z, Y, X);
	}
	return OK;
}
```

## 1.20
``` C
int a[MAXSIZE], x, n;			 //a_i、x_0和n
scanf("%d%d", &n, &x);			 //输入n和x_0
for (int i = 0；i <= n; i++)		//输入a_0到a_n
	scanf("%d", &a[i]);			 //*执行n+1次
int p = 0;						 //p为多项式的值
for (int i = n; i >= 0; i--) {	 //计算多项式的值
	p *= x;						 //*执行n+1次
	p += a[i];					 //*执行n+1次
}
printf("%d", p);				 //输出结果
```
整个算法的时间复杂度为$O(n)$。