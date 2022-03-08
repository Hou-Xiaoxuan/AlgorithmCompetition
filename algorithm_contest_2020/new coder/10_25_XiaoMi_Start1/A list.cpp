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
int prim[int(1e4)+5];
bool viss[int(1e4)+5];
int cnt_prim=0;
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    for(int i=2;i<10000;i++)
    {
        if(viss[i]==false)
        {
            prim[++cnt_prim]=i;
            for(int j=i*2;j<=10000;j+=i)
                viss[j]=true;
        }
    }

    int n;cin>>n;
    vector<LL> a(n+1);
    vector<int> vis(1e7+5);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vis[a[i]]++;
    }
    sort(a.begin(),a.end());
    int ans=1;
    while(ans<=n){
        if(a[ans]==1) ans++;
        else break;
    }
    ans--;
    int sum=0;
    for(int i=ans+1;i<=n;i++)//最小值a[i]
    {
        for(int j=1;a[i]*prim[j]<=a[n];j++)//每次乘prim[j]
        {
            int cnt_tmp=vis[a[i]];
            for(LL k=prim[j];a[i]*k<=a[n];k*=prim[j])//统计个数
                if(vis[a[i]*k]) cnt_tmp+=vis[a[i]*k];
            sum=max(sum,cnt_tmp);
        }
    }
    cout<<sum+ans<<endl;
    return 0;
}