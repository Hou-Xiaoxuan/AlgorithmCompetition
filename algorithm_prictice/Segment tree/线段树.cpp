#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[1 << 15];//����ԭʼ���ݣ�����֮ǰ
int tree[1 << 16] = {0};
int cov[1 << 16] = { 0 };//��¼�Ƿ����޸�
void build(int nod,int l,int r);
int ask(int nod, int l, int r, int x);//�����ѯ
int ask(int nod, int l, int r, int ql, int qr);//�����ѯ
void change(int nod, int l, int r, int x, int y);//����ı�ֵ
void change(int nod, int l, int r, int ql, int qr,int x);//����ı�ֵ(������������������+x
void pushdown(int nod, int l, int r);//�����޸ĵı���·�
void show(int n);

void build(int nod, int l, int r)
{
	if (l == r) {
		tree[nod] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(nod << 1, l, mid);
	build(nod << 1 | 1, mid + 1, r);
	tree[nod] = tree[nod << 1] + tree[nod << 1 | 1];
	return;
}
int ask(int nod, int l, int r, int x)//��ѯA[x]��ֵ
{
	//cout << l << " " << r << " " <<nod<<" "<< x<<endl;
	if (l == r)
		return tree[nod];
	/*����,��������Ҫ�����ӽڵ��ʱ��*/  pushdown(nod, l, r);
	int mid = l + r >> 1;
	
	if (x > mid) return ask(nod << 1 |1, mid+1, r, x);
	else return ask(nod << 1, l, mid, x);
}
int ask(int nod, int l, int r, int ql, int qr)
{
	int mid = l + r >> 1;
	if (ql <= l and qr>=r)  return tree[nod];//����Ѿ���ȫ�����˲���
	//if (qr >= r and ql<=l)  return tree[nod];//�ҵ�д����������==Ҳ����
	/*����,��������Ҫ�����ӽڵ��ʱ��*/  pushdown(nod, l, r);
	int sum = 0;
	if (ql <= mid)//����б�Ҫ����ߵĻ���������ߵ�Ԫ�أ�
		sum += ask(nod<<1,l, mid, ql, qr);
	if (qr > mid)//����б�Ҫ���ұߵĻ��������ұߵ�Ԫ�أ�
		sum += ask(nod<<1|1,mid + 1, r, ql, qr);
	return sum;
}
void show(int n)
{
	int m = log2(n) + 1;
	for (int i = 1; i <= m; i++)
	{
		for (int j = pow(2,i-1); j < pow(2, i);j++) printf("%-5d", tree[j]);
		cout << endl;
	}
}
void change(int nod, int l, int r, int x,int y)
{
	if (l == r) {
		tree[nod] = y;
		return;
	}
	/*����,��������Ҫ�����ӽڵ��ʱ��*/  pushdown(nod, l, r);
	int mid = l + r >> 1;
	if (x > mid) 
		change(nod << 1 | 1, mid + 1, r, x, y);
	else 
		change(nod << 1, l, mid, x, y);

	tree[nod] = tree[nod << 1] + tree[nod << 1 | 1];
	return;
}
void change(int nod, int l, int r, int ql, int qr,int x)//����ٶ��ǽ����е���������x�����������������ͬ
{
	if (ql <= l and qr >= r) {
		tree[nod] += (l-r+1)*x;//�����ӽڵ�+x�൱���Լ�+x*��l-r+1����
		cov[nod] += x;//��������Ľڵ㶼������x
		return;
	}
	/*����,��������Ҫ�����ӽڵ��ʱ��*/  pushdown(nod, l, r);
	int mid = r + l >> 1;
	if (ql <= mid)
		change(nod << 1, l, mid, ql, qr);
	else
		change(nod << 1 | 1, mid + 1, r, ql, qr);
	return;
}
void pushdown(int nod, int l, int r)
{
	if (cov[nod]) {//������ڱ��
		int mid = l + r >> 1;
		tree[nod << 1] += cov[nod] * (mid - l + 1);
		tree[nod << 1 | 1] = cov[nod] * (r - mid);
		cov[nod << 1] = cov[nod << 1 | 1] += cov[nod];
		cov[nod] = 0;
	}
}
int main()
{
	freopen("C:/Users/94726/Desktop/in.txt","r", stdin);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	//change(1, 1, n, 6, 100);
	//int a = ask(1, 1, n, 5); printf("a[5]=%d\n", a);
	//int c = ask(1, 1, n, 6); printf("a[6=]%d\n", c);
	//int b = ask(1, 1, n, 5, 6); printf("a 5~6=%d\n", b);
	//show(n);

	int a1 = ask(1, 1, n, 1, 5); printf("%d\n", a1);
	change(1, 1, n, 4, 5);
	int a2 = ask(1, 1, n, 1, 5); printf("%d\n", a2);
	change(1, 1, n, 3, 6, 1);
	int a3 = ask(1, 1, n, 1, 5); printf("%d\n", a3);
	return 0;
}
