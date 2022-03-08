#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 1e5 + 2;
long long tree[4 * N], cov[4 * N];
void build(int nod, int l, int r);
long long ask(int nod, int l, int r, int ql, int qr);
void change(int nod, int l, int r, int ql, int qr,int y);
void putdown(int nod,int l,int r);
int main()
{
	freopen("C:/Users/94726/Desktop/in.txt", "r", stdin);
	int n, m;
	while (EOF!=scanf("%d%d", &n, &m))
	{
		memset(tree, 0, sizeof(tree));
		memset(cov, 0, sizeof(cov));
		build(1, 1, n);
		while (m--)
		{
			char ch[5]; int a, b, c;
			scanf("%s", ch);
			if (ch[0] == 'C') {
				scanf("%d%d%d", &a, &b, &c);
				change(1, 1, n, a, b, c);
			}
			else if (ch[0] == 'Q') {
				scanf("%d%d", &a, &b);
				printf("%lld\n", ask(1, 1, n, a, b));
			}
		}
	}

	return 0;
}
void putdown(int nod,int l,int r)
{
	if (cov[nod]) {
		int mid = l + r >> 1;
		tree[nod << 1] += cov[nod] * (mid - l + 1);
		tree[nod << 1 | 1] += cov[nod] * (r - mid);
		cov[nod << 1 | 1] += cov[nod];
		cov[nod << 1] += cov[nod];
		cov[nod] = 0;
	}
}
void build(int nod, int l, int r)
{
	cov[nod] = 0;
	if (l == r) {
		scanf("%lld", tree + nod);
		return;
	}
	int mid = l + r >> 1;
	build(nod << 1, l, mid);
	build(nod << 1 | 1, mid + 1, r);
	tree[nod] = tree[nod << 1] + tree[nod << 1 | 1];
}
void change(int nod, int l, int r, int ql, int qr, int y)
{
	if (ql <= l and qr >= r) {
		tree[nod] += (r - l + 1) * y;/*(红色)这里写成了l-r+1！！（红色）*/
		cov[nod] += y;
		return;
	}
	putdown(nod, l, r);
	int mid = l + r >> 1;
	if(ql<=mid)
		change(nod << 1, l, mid, ql, qr, y);
	if(qr>mid)
		change(nod << 1 | 1, mid + 1, r, ql, qr, y);
	tree[nod] = tree[nod << 1] + tree[nod << 1 | 1];
}
long long ask(int nod, int l, int r, int ql, int qr)
{
	if (ql <= l and qr >= r) return tree[nod];
	putdown(nod, l, r);
	long long ans = 0;
	int mid = l + r >> 1;
	if (ql <= mid)
		ans += ask(nod << 1, l, mid, ql, qr);
	if (qr > mid)
		ans += ask(nod << 1 | 1, mid + 1, r, ql, qr);
	
	return ans;
}