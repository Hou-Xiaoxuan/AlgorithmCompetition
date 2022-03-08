#include<iostream>
#include<cstdio>
//好了，基础完成了，接下来……区间修改
using namespace std;
const int N = 5e4+1;
int tree[4 * N];
int a[N];//0~
int l(int i) { return i << 1; }
int r(int i) { return i << 1 | 1; }
int n, M;int bit;
void build(int M,int n)//不一样的储存的方在于:为了查询边界，叶子节点 整体向右平移了一位。
{
	int bit=M;
	for (int i = bit+1; i <= bit + n; i++)//如果bit=16，那么就是从17开始存的
		scanf("%d", &tree[i]);
	for (int i = bit-1; i>=1; i--)
		tree[i] = tree[l(i)] + tree[r(i)];
}
void add(int M,int x, int y)//a[x]+=y
{
	
	int s = M + x;
	tree[s] += y;//单点修改
	while (s >>= 1)
		tree[s] = tree[l(s)] + tree[r(s)];
}
long long query(int M, int l, int r)
{
	long long ans=0;
	for (int i = l + M-1, j = r + M+1; i^j^1; i >>= 1, j >>= 1)
	{
		if (i&1^1 ) //由于平移了一位，这里的转换关系就显得有点抽象。本来应该从16~32存，变成了17~33；
			ans += tree[i + 1];//而在对应父节点时，实际上叶子节点的数目增加了2，（15~34都被当成了叶子节点，但是值为0）
			//这样的话，我想查询1~3，转换后就是17~19；这样的话，我们想储存的值，实际上被放在了更大的一个满二叉树中。求1~3（我们认为的）时，实际求得时2~4（按储存数据的个数）
			
		if (j & 1) 
			ans += tree[j - 1];//关系运算符优先级高于位运算符
	}
	return ans;
}
void show()
{
	for (int i = bit + 1; i <= n+bit; i++)
		cout << tree[i] << " ";
	cout << endl;
}
int main()
{
	//freopen("C:/Users/94726/Desktop/in.txt", "r", stdin);
	int m; scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		printf("Case %d:\n", i);
		 scanf("%d", &n);
		for (bit = 1; bit <= n+1; bit <<= 1);
		build(bit, n);

		while (true)
		{
			char chs[10];
			scanf("%s", chs);
			char ch = chs[0];
			if (ch == 'E') break;
			int x, y;  scanf("%d %d", &x, &y);
			if (ch == 'A')  add(bit, x, y);
			else if (ch == 'S') add(bit, x, -y);
			else if (ch == 'Q')
				//printf("%d\n", query(x, y));
				printf("%lld\n", query(bit, x, y));
		}
		//show();
		//cout << tree[bit];
	}
	return 0;
}