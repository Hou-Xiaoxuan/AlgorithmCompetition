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
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int> a(n+1);
        vector<bool> vis(n+1);
        int d=-1,ind=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]>d){
                d=a[i];
                ind=i;
            }
        }
        vis[ind]=1;
        cout<<a[ind]<<' ';
        for(int k=2;k<=n;k++)
        {
            int cnt=-1;
            for(int i=1;i<=n;i++){
                if(vis[i]==1) continue;
                int tmp=gcd(a[i],d);
                if(cnt<tmp){
                    cnt=tmp;
                    ind=i;
                }
            }
            vis[ind]=1;
            d=cnt;
            cout<<a[ind]<<" ";
        }
        cout<<endl;
    }
    return 0;
}