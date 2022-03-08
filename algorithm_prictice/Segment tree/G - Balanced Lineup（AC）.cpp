#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define L mid<<1
#define R mid<<1|1
#define Mid int mid = l + r >> 1
int dmax[1 << 18],dmin[1<<18];
void build(int nod, int l, int r)
{
	if (l >= r) {
		scanf("%d", &dmax[nod]);
		dmin[nod] = dmax[nod];
		return;
	}
	Mid;
	build(L, l, mid);
	build(R, mid + 1, r);
	dmax[nod] = max(dmax[L], dmax[R]);
	dmin[nod] = min(dmin[L], dmin[R]);
}
void ask(int nod, int l, int r, int ql, int qr,int &x,int &y)
{
	if (ql <= l and qr >= r) {
		x = dmax[nod];
		y = dmin[nod];
		return;
	}
	Mid;
	int a=-1,b=1e6+1;
	if (ql <= mid) {
		ask(L, l, mid, ql, qr, a, b);
		x = max(x, a);
		y = min(y, b);//这里不能积攒，每次得到的a和b必须立刻与x，y进行比较，防止“更优”结果被覆盖掉！
	}
	if (qr > mid) {
		ask(R, mid + 1, r, ql, qr, a, b);
		x = max(x, a);
		y = min(y, b);
	}
}
int main()
{
	//freopen("C:/Users/94726/Desktop/in.txt", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	build(1, 1, n);
	while (m--)
	{
		int a, b,x=-1,y=1e6+1;
		scanf("%d %d", &a, &b);
		ask(1, 1, n, a, b, x, y);
		printf("%d\n", x - y);
	}
	return 0;
}