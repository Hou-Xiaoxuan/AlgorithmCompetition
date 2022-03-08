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
typedef long double LD;
const int inf=0x3f3f3f3f;


int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #elif _LINUX
    freopen("/run/media/linxuan/储存/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("/run/media/linxuan/储存/CODE/algorithm_contest/in.txt","r",stdin);
    #endif

    int t; cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int> a(m+1);
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            a[x%m]++;
        }
        int ans=(a[0]>0);
        for(int i=1;i<m;i++)
        {
            if(m-i==i){//m/2放到一组里面
                if(a[i]) ans++;
                a[i]=0;
                continue;
            }
            int cnt=min(a[i],a[m-i]);//i m-i i m-i i符合规律
            a[i]-=cnt;  a[m-i]-=cnt;
            if(cnt) ans++;
            if(cnt and a[i]>0) a[i]--;
            else if(cnt and a[m-i]>0) a[m-i]--;
            ans+=a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
