/*æ…Ã‚*/
//wocao
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define L nod<<1
#define R nod<<1|1
#define Mid int mid=l+r>>1
#define up tree[nod]=(tree[L]+tree[R])%mod
const int N = 1 << 17;
const int mod = 10007;
int tree[N];
int lasy[N][3];//0:+c 1:*c 2:->C

void build(int nod, int l, int r)
{
	if (l >= r) {
		scanf("%d", &tree[nod]);
		memset(lasy[nod],0, sizeof(int)*3);
		return;
	}
	Mid;
	build(L, l, mid);
	build(R, mid + 1, r);
	memset(lasy[nod], 0, sizeof(int) * 3);
}
void putdown(int nod, int l, int r)
{
	if (lasy[nod][0])
	{
		Mid;
		lasy[L][0] = lasy[R][0] = lasy[nod][0];
		tree[L] += lasy[nod][0] * (mid - l + 1)%mod; tree[L] %= nod;
		tree[R] += lasy[nod][0] * (r - mid) % mod; tree[R] %= nod;
		up;
	}
	if (lasy[nod][1])
	{
		Mid;
		lasy[L][1] = lasy[R][1] = lasy[nod][1];
		tree[L] = (lasy[nod][1] % mod * tree[L]) % mod;
		tree[R] = (lasy[nod][1] % mod * tree[R]) % mod;
		up;
	}
	if (lasy[nod][2])
	{
		Mid;
		lasy[L][2] = lasy[R][2] = lasy[nod][2];
		tree[L] = lasy[nod][2] * (mid - l + 1) % mod;
		tree[R] = lasy[nod][2] * (r - mid) % mod;
		up;
	}
}
void change_1(int nod, int l, int r, int ql,int qr,int c)
{
	if (ql <= l and qr >= r)
	{
		tree[nod] += c % mod; tree[nod] %= mod;
		lasy[nod][0] = c;
		return;
	}
	putdown(nod, l, r);
	Mid;
	if (ql <= mid) change_1(nod,l,mid,ql,qr,c);
	if (qr > mid) change_1(nod, mid + 1, r, ql, qr, c);
	up;
}
void change_2(int nod, int l, int r, int ql, int qr, int c)
{
	if (ql <= l and qr >= r)
	{
		lasy[nod][1] = c;
		tree[nod] = tree[nod] * (c % mod) % mod;
		return;
	}
	putdown(nod, l, r);
	Mid;
	if (ql <= mid) change_2(nod, l, mid, ql, qr, c);
	if (qr > mid) change_2(nod, mid + 1, r, ql, qr, c);
	up;
}
void change_3(int nod, int l, int r, int ql, int qr, int c)
{
	if (ql <= l and qr >= r)
	{
		lasy[nod][2] = c;
		tree[nod] = (r - l + 1) * c % mod;
		return;
	}
	putdown(nod, l, r);
	Mid;
	if (ql <= mid) change_3(nod, l, mid, ql, qr, c);
	if (qr > mid) change_3(nod, mid + 1, r, ql, qr, c);
	up;
}

int ask(int nod, int l, int r, int ql, int qr)
{
	if (ql <= l and qr >= r) return tree[nod];
	Mid;
	int ans = 0;
	if (ql <= mid) ans += ask(nod, l, mid, ql, qr);
	if (qr > mid) ans += ask(nod, mid + 1, r, ql, qr);
	return ans%mod;
}

int main()
{
	freopen("C:/Users/94726/Desktop/in.txt", "r", stdin);
	int n, m;
	while (scanf("%d %d", &n, &m))
	{
		if (m == 0 and n == 0) break;
		build(1, 1, n);
		while (m--)
		{
			int a, b, c, d;
			if (a == 1) change_1(1, 1, n, b, c, d);
			if (a == 2) change_2(1, 1, n, b, c, d);
			if (a == 3) change_3(1, 1, n, b, c, d);
		}
	}
	return 0;
}