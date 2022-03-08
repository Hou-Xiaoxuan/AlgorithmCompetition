//这道题是必须单点更新的，关键在于剪枝，及但目前区间内的数全部都是1是就不需要操作了，以此来

//#1：不需要lasy标记  #2：long long数据范围  #3：未说明l<r  #4：格式：要有空格
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define L (nod<<1)
#define R (nod<<1|1)
#define Mid int mid=(l+r>>1)
#define up d[nod]=d[L]+d[R]
long long d[1 << 18];
void build(int nod, int l, int r)
{
	if (l >= r) {
		scanf("%lld", &d[nod]);
		return;
	}
	Mid;
	build(L, l, mid);
	build(R, mid + 1, r);
	up;
}
void change(int nod, int l, int r, int ql, int qr)
{
	if (r - l + 1 == d[nod]) return;
	if (l >= r) {
		d[nod] = (int)sqrt(d[nod]);
		return;
	}
	Mid;
	if (ql <= mid) change(L, l, mid, ql, qr);
	if (qr > mid) change(R, mid + 1, r, ql, qr);
	up;
}
long long query(int nod, int l, int r, int ql, int qr)
{
	if (r - l + 1 == d[nod]) return min(qr,r)-max(ql,l)+1;
	if (l >= r) return d[nod];
	long long ans = 0;
	Mid;
	if (ql <= mid) 
		ans += query(L, l, mid, ql, qr);
	if (qr > mid) 
		ans += query(R, mid + 1, r, ql, qr);
	up;
	return ans;
}
int main()
{
	//freopen("C:/Users/94726/Desktop/in.txt", "r", stdin);
	int n, cnt = 1;
	while (EOF != scanf("%d", &n))
	{
		printf("Case #%d:\n", cnt++);
		build(1, 1, n);
		int m; scanf("%d", &m);
		while (m--)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			if (b > c) swap(b, c);
			if (a == 0)	change(1, 1, n, b, c);
			else	printf("%lld\n", query(1, 1, n, b, c));
		}
		printf("\n");
	}
	return 0;
}