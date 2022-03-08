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
// AC
LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #else
    freopen("halfnice.in","r",stdin);
    #endif

    // 欧拉筛
    const int N=1e7;
    int tot=0;
    vector<int> prim(N+5);
    vector<bool> vis(N+5);
    vis[0]=vis[1]=true;
    for(int i=2;i<=N;i++)
    {
        if(vis[i]==false) prim[++tot]=i;
        for(int j=1;j<=tot and i*prim[j]<=N;++j)
            vis[i*prim[j]]=true;
    }
    int t;cin>>t;
    for(int index=1;index<=t;index++)
    {
        LL left,right;
        cin>>left>>right;
        bool flag=false;
        LL ans=-1;
        while(left<=right)
        {
            LL pre,past;
            LL tmp=right,cnt=0;
            while(tmp){
                tmp/=10;
                ++cnt;
            }
            pre=right/LL(pow(10,(cnt+1)/2));
            past=right%LL(pow(10,(cnt+1)/2));
            if(vis[pre]==false)//如果pre是质数的话，
            {
                if(pre<=past)
                {   
                    ans=right-past%pre;
                    if(ans>=left) flag=true;
                    else flag=false;
                    break;
                }
                else
                    right-=past+1;
            }
            else
            {
                if(gcd(pre,past)>1 and past!=0)
                {
                    flag=true;
                    ans=right;
                    break;
                }
                else
                    --right;
            }
        }
        cout<<"Case "<<index<<": ";
        if(flag==true)
            cout<<ans<<endl;
        else
            cout<<"impossible"<<endl;
    }

    return 0;
}
