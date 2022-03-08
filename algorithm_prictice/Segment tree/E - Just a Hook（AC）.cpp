//ËÄ±¶¿Õ¼ä
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define L (nod<<1)
#define R (nod<<1|1)
#define push (d[nod]=d[L]+d[R])
int d[1 << 18],lasy[1<<18],dat[100005];
void pushdown(int nod, int l, int r)
{
	if (lasy[nod]!=0)
	{
		int mid = l + r >> 1;
		lasy[L] = lasy[R] = lasy[nod];
		d[L] = lasy[nod] * (mid - l + 1);
		d[R] = lasy[nod] * (r - mid);
		lasy[nod] = 0;
	}
}
void build(int nod, int l, int r)
{
	if (l >= r) {
		d[nod]=dat[l];
		lasy[nod] = 0;
		return;
	}
	int mid = l + r >> 1;
	build(L, l, mid);
	build(R, mid + 1, r);
	lasy[nod] = 0;
	push;
}
void change(int nod, int l, int r,int ql,int qr,int y)
{
	if (ql<=l and qr>=r) {
		d[nod] = y*(r-l+1);
		lasy[nod] = y;
		return;
	}
	pushdown(nod, l, r);
	int mid = l + r >> 1;
	if (ql <= mid) change(L, l, mid,ql,qr,y);
	if (qr > mid) change(R, mid + 1, r,ql,qr, y);
	push;
}
int read()
{
	char ch;
	ch = getchar();
	while (ch < '0' or ch>'9') ch = getchar();
	int temp = 0;
	while (ch >= '0' and ch <= '9') {
		temp = temp * 10 + ch - '0';
		ch = getchar();
	}
	return temp;
}
int main()
{
	//freopen("C:/Users/94726/Desktop/in.txt", "r", stdin);
	//ios::sync_with_stdio(false);
	int t;//cin >> t;
	scanf("%d", &t);
	for(int i=1;i<=t;i++)
	{
		int n; //cin >> n;
		scanf("%d", &n);
		//n = read();
		int m; //cin >> m;
		scanf("%d", &m);
		//m = read();
		int a,b,c;
		//a = read(); b = read(); c = read();
		scanf("%d %d %d", &a, &b, &c);
		for (int i = 1; i <= n; i++)
		{
			if (i >= a and i <= b) dat[i] = c;
			else dat[i] = 1;
		}
		build(1, 1, n);
		m--;
		while(m--)
		{
			//cin >> a >> b >> c;
			scanf("%d %d %d", &a, &b, &c);
			//a = read(); b = read(); c = read();
			change(1, 1, n, a, b, c);
		}
		//cout << "Case " << i << ": The total value of the hook is " << d[1] << ".\n";
		printf("Case %d: The total value of the hook is %d.\n", i, d[1]);
	}
	return 0;
}