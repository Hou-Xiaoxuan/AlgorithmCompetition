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

    int n,k;
    const int mod=1e9+7;
    while(cin>>n>>k)
    {
        vector<vector<LL>> num(n+1,vector<LL>(k+1));//i维数，%k=j
        for(int i=1;i<=6;i++)
            num[1][i%k]++;
        for(int i=0;i<n;i++)
            for(int j=0;j<k;j++)
            {
                for(int r=1;r<=6;r++){
                    num[i+1][(10*j+r)%k]+=num[i][j];
                    num[i+1][(10*j+r)%k]%=mod;
                }
            }
        cout<<num[n][0]%mod<<endl;
    }

    return 0;
}
