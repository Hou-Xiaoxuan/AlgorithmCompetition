#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define x first
#define y second 
using namespace std;
using LL=long long;
using ULL=unsigned long long;
using P=pair<int,int>;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;

LL get(int x,int n,vector<int>& a)
{
        int cnt=0;
        int maxn=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=x) cnt++;
            else
            {
                maxn=max(cnt,maxn);
                cnt=0;
            }
        }
        maxn=max(maxn,cnt);
        return maxn*x;

}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #elif _LINUX
    freopen("/media/linxuan/储存/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("/media/linxuan/储存/CODE/algorithm_contest/in.txt","r",stdin);
    #endif
    
    // try n^2
    // WC,果然暴力出奇迹
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> vis(1e5+5);
    for(int i=1;i<=n;i++) cin>>a[i];
    
    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[a[i]]==true) continue;
        else ans=max(ans,get(a[i],n,a));
        vis[a[i]]=true;
    }
    cout<<ans<<endl;
    return 0;
}
