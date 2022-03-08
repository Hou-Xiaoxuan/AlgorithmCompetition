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
using LD=long double;
using P=pair<int,int>;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;

int n,m,k;
vector<P> condition,opration;
vector<int> vis;
int dfs(int i)
{
    if(i>k)
    {
        int cnt=0;
        for(int i=1;i<=m;i++)
            if(vis[condition[i].x]>0 and vis[condition[i].y]>0) cnt++;
        return cnt;
    }
    vis[opration[i].x]++;
    int ans1=dfs(i+1);
    vis[opration[i].x]--;
    vis[opration[i].y]++;
    int ans2=dfs(i+1);
    vis[opration[i].y]--;
    return max(ans1,ans2);
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #endif
    cin>>n>>m;
    condition.assign(m+1,P(0,0));
    vis.assign(n+1,0);
    for(int i=1;i<=m;i++)
        cin>>condition[i].x>>condition[i].y;
    cin>>k;
    opration.assign(k+1,P(0,0));
    for(int i=1;i<=k;i++)
        cin>>opration[i].x>>opration[i].y;
    int ans=dfs(1);
    cout<<ans<<endl;
    return 0;
}
