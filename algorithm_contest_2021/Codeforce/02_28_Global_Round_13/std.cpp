#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long 
#define MEM(x,y) memset(x,y,sizeof(x))
#define int long long
#define rep(i , a , b) for(int i = a ; i <= b ; i ++)
#define P pair<int,int>
#define  sc(a) scanf("%lld",&a)
#define pf(a) printf("%lld ",a)
using namespace std;
const int N = 300010, INF = 0x3f3f3f3f3f3f;
int T;
int a[N];
int n, m;
int cnt[N];
int x;
int k,ans;
signed main()
{

	sc(T);
	while (T--)
	{

		sc(n);
		rep(i, 0, n - 1)
		{
			sc(a[i]);
			cnt[i] = 0;
		}
		 ans = 0;
		for (int i = 0; i < n; i++)
		{
			x = max(a[i] - 1 - cnt[i], 0ll);
			ans += x;
			k = i + 2;
			x = min(i + a[i], n - 1);
			while (k <= x)
			{
				cnt[k]++;
				k++;
			}
			cnt[i + 1] += max(cnt[i] - a[i] + 1, 0ll);
		}
		cout << ans << endl;
	}

}
