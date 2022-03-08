//思路：从后往前贴，贴过的不再贴；
//考试完再全部重新打

//哈哈哈哈哈哈哈哈哈哈哈，我过了！！！！！！！！！！
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
const int N = 4e5 + 1;
bool vis[N];
int a[N], b[N], tree[N];
map<int, int> ma;
#define left (nod << 1)
#define right (nod<<1|1)
void build(int nod, int l, int r)
{
	if (l >= r) {
		vis[nod] = false;
		return;
	}
	int mid=l+r>>1;
	build(left, l, mid);
	build(right, mid + 1, r);
	vis[nod] = false;
}
bool change(int nod, int l, int r, int ql, int qr)
{
	if (vis[nod]) return false;
	if (ql <= l and qr >= r) {
		vis[nod] = true;
		return true;
	}
	int mid = l + r >> 1;
	bool flag1 = false,flag2=false;
	if (ql <= mid) flag1 = change(left, l, mid, ql, qr);
	if (qr > mid) flag2 = change(right, mid + 1, r, ql, qr);
	vis[nod] = vis[left] and vis[right];
	return (flag1 or flag2);
}
int main()
{
	//freopen("C:/Users/94726/Desktop/in.txt", "r",stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		//memset(vis, 0, sizeof(vis));
		int m; scanf("%d", &m);
		for (int i = 1; i < 2 * m; i += 2) {
			scanf("%d %d", a + i, a + i + 1);
			b[i] = a[i]; b[i + 1] = a[i + 1];
		}
		sort(b + 1, b + 2 * m + 1);//排序
		int n = unique(b + 1, b + 1 + m * 2) - b - 1;//去重
		for (int i = 1; i <= n; i++) {//离散化
			ma[b[i]] = i;
			//cout <<b[i]<<"-"<< ma[b[i]] << endl;
		}
		build(1, 1,n);
		int ans = 0;
		for (int i = 2 * m; i >= 1; i -= 2) {
			//cout << a[i - 1] << " " << a[i] << endl;
			if (change(1, 1, n, ma[a[i - 1]], ma[a[i]])==true)
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}