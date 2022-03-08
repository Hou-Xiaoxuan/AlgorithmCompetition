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

// 艹tm的数论
int main()
{
    IOS;
    #ifdef _DEBU
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #endif
    
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

    vector<int> num(61);
    for(int i=2;i<=60;i++)
    {
        int tmp=i;
        int cnt=1;//i的因数个数
        for(int j=1;prim[j]<=tmp and tmp>1;j++)
        {
            if(tmp%prim[j]==0)
            {
                int ct=0;
                while(tmp%prim[j]==0){
                    ct++;
                    tmp/=prim[j];
                }
                cnt*=(ct+1);
            }
        }
        num[i]=cnt-1+num[i-1];
    }

    LL n;
    cin>>n;
    LL cnt=0;
    // init_prime();
    for(int i=1;prim[i]<=sqrt(n);i++)
    {
        int k=log(n)/log(prim[i]);
        cnt+=num[k];
    }
    cout<<n-cnt<<endl;
    return 0;
}
