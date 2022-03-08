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
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    const int N=100000005;
    vector<bool> is(N); is[2];
    for(int i=2;i<=N;i++)
    {
        if(is[i]==false)//如果是质数
            for(int j=2;i*j<=N;j++)
                is[i*j]=true;
    }
    vector<int>ans(N);
    for(int i=1;i*2<=N;i++)
        for(int j=1;i*j<=N;j++)
            ans[i*j]=max(i*j,ans[i*j]);
    vector<int> sum;
    for(int i=1;i<=N;i++)
        if(is[i]==false)
            sum.push_back(i); 
    
        int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int cnt=lower_bound(sum.begin(),sum.end(),n>>1)-sum.begin();
        // cout<<sum[cnt]<<endl;
        cout<<(n>>1)<<endl;


    }
    return 0;
}