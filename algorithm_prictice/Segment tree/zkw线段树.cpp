#include<iostream>
#include<cstdio>
//���ˣ���������ˣ����������������޸�
using namespace std;
const int N = 5e4+1;
int tree[4 * N];
int a[N];//0~
int l(int i) { return i << 1; }
int r(int i) { return i << 1 | 1; }
int n, M;int bit;
void build(int M,int n)//��һ���Ĵ���ķ�����:Ϊ�˲�ѯ�߽磬Ҷ�ӽڵ� ��������ƽ����һλ��
{
	int bit=M;
	for (int i = bit+1; i <= bit + n; i++)//���bit=16����ô���Ǵ�17��ʼ���
		scanf("%d", &tree[i]);
	for (int i = bit-1; i>=1; i--)
		tree[i] = tree[l(i)] + tree[r(i)];
}
void add(int M,int x, int y)//a[x]+=y
{
	
	int s = M + x;
	tree[s] += y;//�����޸�
	while (s >>= 1)
		tree[s] = tree[l(s)] + tree[r(s)];
}
long long query(int M, int l, int r)
{
	long long ans=0;
	for (int i = l + M-1, j = r + M+1; i^j^1; i >>= 1, j >>= 1)
	{
		if (i&1^1 ) //����ƽ����һλ�������ת����ϵ���Ե��е���󡣱���Ӧ�ô�16~32�棬�����17~33��
			ans += tree[i + 1];//���ڶ�Ӧ���ڵ�ʱ��ʵ����Ҷ�ӽڵ����Ŀ������2����15~34����������Ҷ�ӽڵ㣬����ֵΪ0��
			//�����Ļ��������ѯ1~3��ת�������17~19�������Ļ��������봢���ֵ��ʵ���ϱ������˸����һ�����������С���1~3��������Ϊ�ģ�ʱ��ʵ�����ʱ2~4�����������ݵĸ�����
			
		if (j & 1) 
			ans += tree[j - 1];//��ϵ��������ȼ�����λ�����
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