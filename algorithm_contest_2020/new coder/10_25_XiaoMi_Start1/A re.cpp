#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;
int prim[int(1e7)+5];
bool viss[int(1e7)+5];
int cnt_prim=0;
// 根据题解，素数倍DP更新
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    // 埃式筛:
    for(int i=2;i<10000000;i++)
    {
        if(viss[i]==false)
        {
            prim[++cnt_prim]=i;
            for(int j=i*2;j<=10000000;j+=i)
                viss[j]=true;
        }
    }

    int n;cin>>n;
    vector<int> a(n+1);
    vector<int> num(1e7+5),mp(1e7+5);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        num[a[i]]++;
    }
    sort(a.begin()+1,a.end());
    int m=unique(a.begin()+1,a.end())-a.begin()-1;
    vector<int> f(a[m]+5);
    for(int i=1;i<=m;i++){
        mp[a[i]]=i;
        f[a[i]]=num[a[i]];
    }
    for(int i=1;i<=a[m];i++)
    {
        if(f[i]==0) continue;
        for(int j=1;LL(i)*prim[j]<=a[m];j++)
        {
            int tmp=i*prim[j];
            f[tmp]=max(f[tmp],f[i]+num[tmp]);
        }
    }
    int ans=0;
    for(int i=1;i<=a[m];i++) ans=max(f[i],ans);
    cout<<ans<<endl;
    return 0;
}