#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[1 << 15];//保存原始数据：建树之前
int tree[1 << 16] = {0};
int cov[1 << 16] = { 0 };//记录是否有修改
void build(int nod,int l,int r);
int ask(int nod, int l, int r, int x);//单点查询
int ask(int nod, int l, int r, int ql, int qr);//区间查询
void change(int nod, int l, int r, int x, int y);//单点改变值
void change(int nod, int l, int r, int ql, int qr,int x);//区间改变值(这里是区间所有数据+x
void pushdown(int nod, int l, int r);//区间修改的标记下放
void show(int n);

void build(int nod, int l, int r)
{
	if (l == r) {
		tree[nod] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(nod << 1, l, mid);
	build(nod << 1 | 1, mid + 1, r);
	tree[nod] = tree[nod << 1] + tree[nod << 1 | 1];
	return;
}
int ask(int nod, int l, int r, int x)//查询A[x]的值
{
	//cout << l << " " << r << " " <<nod<<" "<< x<<endl;
	if (l == r)
		return tree[nod];
	/*增加,在所有需要访问子节点的时候*/  pushdown(nod, l, r);
	int mid = l + r >> 1;
	
	if (x > mid) return ask(nod << 1 |1, mid+1, r, x);
	else return ask(nod << 1, l, mid, x);
}
int ask(int nod, int l, int r, int ql, int qr)
{
	int mid = l + r >> 1;
	if (ql <= l and qr>=r)  return tree[nod];//如果已经完全包括此部分
	//if (qr >= r and ql<=l)  return tree[nod];//我的写法在这里用==也可以
	/*增加,在所有需要访问子节点的时候*/  pushdown(nod, l, r);
	int sum = 0;
	if (ql <= mid)//如果有必要查左边的话（存在左边的元素）
		sum += ask(nod<<1,l, mid, ql, qr);
	if (qr > mid)//如果有必要查右边的话（存在右边的元素）
		sum += ask(nod<<1|1,mid + 1, r, ql, qr);
	return sum;
}
void show(int n)
{
	int m = log2(n) + 1;
	for (int i = 1; i <= m; i++)
	{
		for (int j = pow(2,i-1); j < pow(2, i);j++) printf("%-5d", tree[j]);
		cout << endl;
	}
}
void change(int nod, int l, int r, int x,int y)
{
	if (l == r) {
		tree[nod] = y;
		return;
	}
	/*增加,在所有需要访问子节点的时候*/  pushdown(nod, l, r);
	int mid = l + r >> 1;
	if (x > mid) 
		change(nod << 1 | 1, mid + 1, r, x, y);
	else 
		change(nod << 1, l, mid, x, y);

	tree[nod] = tree[nod << 1] + tree[nod << 1 | 1];
	return;
}
void change(int nod, int l, int r, int ql, int qr,int x)//这里假定是将所有的数都增加x倍，其他操作大抵相同
{
	if (ql <= l and qr >= r) {
		tree[nod] += (l-r+1)*x;//所有子节点+x相当于自己+x*（l-r+1）；
		cov[nod] += x;//记下下面的节点都增加了x
		return;
	}
	/*增加,在所有需要访问子节点的时候*/  pushdown(nod, l, r);
	int mid = r + l >> 1;
	if (ql <= mid)
		change(nod << 1, l, mid, ql, qr);
	else
		change(nod << 1 | 1, mid + 1, r, ql, qr);
	return;
}
void pushdown(int nod, int l, int r)
{
	if (cov[nod]) {//如果存在标记
		int mid = l + r >> 1;
		tree[nod << 1] += cov[nod] * (mid - l + 1);
		tree[nod << 1 | 1] = cov[nod] * (r - mid);
		cov[nod << 1] = cov[nod << 1 | 1] += cov[nod];
		cov[nod] = 0;
	}
}
int main()
{
	freopen("C:/Users/94726/Desktop/in.txt","r", stdin);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	//change(1, 1, n, 6, 100);
	//int a = ask(1, 1, n, 5); printf("a[5]=%d\n", a);
	//int c = ask(1, 1, n, 6); printf("a[6=]%d\n", c);
	//int b = ask(1, 1, n, 5, 6); printf("a 5~6=%d\n", b);
	//show(n);

	int a1 = ask(1, 1, n, 1, 5); printf("%d\n", a1);
	change(1, 1, n, 4, 5);
	int a2 = ask(1, 1, n, 1, 5); printf("%d\n", a2);
	change(1, 1, n, 3, 6, 1);
	int a3 = ask(1, 1, n, 1, 5); printf("%d\n", a3);
	return 0;
}
