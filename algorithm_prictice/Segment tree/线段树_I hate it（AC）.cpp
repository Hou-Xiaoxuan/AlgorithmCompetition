#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int M = 1<<19;
int tree[4 * M];
int n, m, bit=1;
void change(int a,int b)
{
	int s = a + bit;
	tree[s] = b;
	
	while (s>>=1) tree[s] = max(tree[s << 1] , tree[s << 1 | 1]);
}
int ask(int x, int y)//�������ֵ
{
	int ans = -1;
	for (int l = x - 1+bit, r = y + 1+bit; l ^ r ^ 1; l >>= 1, r >>= 1)
	{
		if (~l & 1) ans = max(ans, tree[l + 1]);
		if (r & 1) ans = max(ans, tree[r - 1]);
	}
	return ans;
}
int main()
{
	//freopen("C:/Users/94726/Desktop/in.txt", "r", stdin);
	
	while (scanf("%d %d", &n, &m) == 2)//�����ԵĶ������룻
		//��˵���ؿ�ζ�Ķ���ʱN���������һ�û��ѧ�ؼ���
	{
		memset(tree, 0, sizeof(tree));
		while (bit <= n + 1)  bit <<= 1;
		for (int i = bit + 1; i <= bit + n; i++)
			scanf("%d", tree + i);
		for (int i = bit - 1; i >= 1; i--)
			tree[i] = max(tree[i << 1], tree[i << 1 | 1]);//��ɽ���
		while (m--)
		{
			char ch[5]; int x, y;
			scanf("%s", &ch);
			scanf("%d %d", &x, &y);
			if (ch[0] == 'U') change(x, y);
			else if (ch[0] == 'Q') printf("%d\n", ask(x, y));
		}

	}
	return 0;
}