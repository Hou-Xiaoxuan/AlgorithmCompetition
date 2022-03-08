//https://www.luogu.com.cn/problem/P1440
//template
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_k make_pair
#define   P  pair<int,int>
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;

int main()
{
    IOS
    priority_queue<P,vector<P>, greater<P> >que;
    int n,m;cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    cout<<0<<endl;//use printf and scanf to AC
    que.push(m_k(a[1],1));
    for(int i=2;i<=n;i++)
    {
        while(que.top().second<i-m) que.pop();
        cout<<que.top().first<<endl;
        que.push(m_k(a[i],i));
    }
    return 0;
}