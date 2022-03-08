#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
//我的read函数有问题，果然，我的输入输出是短板 
const int N= 5e4+1;
int tree[4 * N];
int a[N];
void build(int nod,int l,int r)
{
	if (l == r) {
		tree[nod] = a[l]; return;
	}
	int mid = l + r >> 1;
	build(nod << 1, l, mid);//建立左子树
	build(nod << 1 | 1, mid + 1, r);//右子树
	tree[nod] = tree[nod << 1] + tree[nod << 1 | 1];
	return;
}
 long long ask(int nod, int l, int r,int ql,int qr)//求区间和
{
	if (ql <= l and qr >= r)
		return tree[nod];

	int mid = l + r >> 1;
	int ans = 0;
	if (qr > mid)
		ans += ask(nod << 1 | 1, mid + 1, r, ql, qr);
	if (ql <= mid)
		ans += ask(nod << 1, l, mid, ql,qr);
	return ans;
}
void add(int nod, int l, int r, int x, int y)//a[x]+=y; 
{
	if (l == r) {
		tree[nod] += y;
		return;
	}
	int mid = l + r >> 1;
	if (x <= mid) add(nod << 1, l, mid, x, y);
	else add(nod << 1 | 1, mid + 1, r, x, y);
	tree[nod] = tree[nod << 1] + tree[nod << 1 | 1];//忘记更新祖先了
}
void show(int n)//查看原数组结果，题目中没有用到。
{
	for (int i = 1; i <= n; i++)
		printf("%d ", ask(1, 1, n, i, i));
	cout << endl;
}
void read(char& temp)//读字符串首字母
{
	char ch;
	int cnt = 1;
	ch = getchar();
	while (ch < 'A' or ch>'Z') ch = getchar();
	temp = ch;
	while (ch != ' ') ch = getchar();
}
int read()//读整数
{
	char ch = 'a';
	int temp = 0;
	while (ch < '0' or ch > '9') ch = getchar();
	while (ch >= '0' and ch <= '9') { temp = temp * 10 + ch - '0'; ch = getchar(); }
	return temp;
}
int main()
{
	//freopen("C:/Users/94726/Desktop/in.txt", "r", stdin);
	int t; //t = read();
	scanf("%d",&t);
	for(int j=1;j<=t;j++)
	{
		int n;// n = read();
		scanf("%d",&n);
		for (int i = 1; i <= n; i++)
		scanf("%d",a+i);
			//a[i] = read();
		build(1, 1, n);
		char temp[20];
		printf("Case %d:\n", j);
		while (1)
		{
			scanf("%s",temp);
			if (temp[0]=='E') break;
			int x, y;
			//x = read(); y = read();
			scanf("%d %d",&x,&y);
			if (temp[0]=='Q') {
				printf("%lld\n", ask(1, 1, n, x, y));
			}
			else if (temp[0]=='A')
				add(1, 1, n, x, y);
			else if (temp[0]=='S')
				add(1, 1, n, x, -y);
			//show(n);
		}
	}
	return 0;
}
