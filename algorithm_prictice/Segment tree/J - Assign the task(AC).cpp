//�ҵ�ask��Ҫ�ݹ�ĸ��������ڵ�����У������ǳ���ʲô���⡣�����������£�Ҳ���ᳬʱ����Ȼ���ˡ�
//�ٳ��֣����������
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N = 1e5 + 5;
int a[N],order[N],boss[N];//��ʾĿǰ��״̬���������ȼ���
int ans[2];
bool ask(int x,int k)//x�ǳ�Ա��ţ�k�ǵȼ�
{
	int t = boss[x];
	bool flag = false;
	if (order[t] >k) {//���и����ȼ�
		ans[0] = a[t]; a[1] = order[t];
		flag = true;
	}
	if (t == boss[t]) return false;//�ݹ������־
	if (ask(t, order[t]))//��������ٴη������µĻ������������
	{
		a[t] = ans[0]; order[t] = ans[1];
		flag = true;
	}
	return flag;
}
void ask(int t)
{
	int x = t;
	while (x != boss[x])
	{
		x = boss[x];
		if (order[x] > ans[1])
			ans[0] = a[x], ans[1] = order[x];
	}
	if (ans[0] != a[t])
		a[t] = ans[0], order[t] = ans[1];
}
int main()
{
	//freopen("C:/Users/94726/Desktop/in.txt", "r", stdin);
	int T; scanf("%d", &T);
	for(int i=1;i<=T;i++)
	{
		printf("Case #%d:\n", i);
		int n; scanf("%d", &n);
		for (int i = 1; i <=n; i++) {
			a[i] = -1, boss[i] = i; order[i] = 0;
		}
		for (int i = 1; i < n; i++)
		{
			int ia, ib; scanf("%d %d", &ia, &ib);
			boss[ia] = ib;
		}
		int m; scanf("%d", &m);
		for (int i = 1; i <= m; i++)
		{
			char ch[10]; scanf("%s", ch);
			if (ch[0] == 'T') {
				int x, y; scanf("%d %d", &x, &y);
				a[x] = y;
				order[x] = i;
			}
			else {
				int x; scanf("%d", &x);
				ans[0] = a[x]; ans[1] = order[x];
				//ask(x, order[x]);
				ask(x);
				printf("%d\n", ans[0]);
			}
		}
	}
	return 0;
}
