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

    int n,k;
    cin>>n>>k;
    vector<int> a(n+1),b(k+1);//服务器、指令
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int j=1;j<=k;j++) cin>>b[j];
    vector<int> ans(n+1);
    for(int i=1;i<=n;i++) ans[i]=i;
    do
    {
        if(n<k) break;
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            if(b[i]<=a[ans[i]]) continue;
            else flag=false;
        }
        if(flag==true)
        {
            for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
            cout<<endl;
            return 0;
        }
        
    } while (next_permutation(ans.begin()+1,ans.end()));
    cout<<-1<<endl;
    return 0;
}
