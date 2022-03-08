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
// 还是有点迷迷糊糊，不是很理解，先敲一遍吧
// 题解：https://blog.csdn.net/a1799342217/article/details/80489165
const int N=1e3;
int a1[N+5][N+5],a2[N+5][N+5],a3[N+5][N+5],a4[N+5][N+5];
LL c3[100005];
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    for(int i=3;i<=100000;i++){
        c3[i]=1ll*i*(i-1)*(i-2)/6;
    }
    int t;cin>>t;
    while(t--)
    {
        memset(a1,0,sizeof(a1));
        memset(a2,0,sizeof(a2));
        memset(a3,0,sizeof(a3));
        memset(a4,0,sizeof(a4));
        int n; cin>>n;
        int x1,y1,x2,y2;
        for(int i=1;i<=n;i++)
        {
            cin>>x1>>y1>>x2>>y2;
            a1[x1][y1]++; a1[x2+1][y2+1]++;
            a1[x1][y2+1]--; a1[x2+1][y1]--;

            a2[x1+1][y1]++; a2[x2+1][y2+1]++;
            a2[x1+1][y2+1]--; a2[x2+1][y1]--;

            a3[x1][y1+1]++; a3[x2+1][y2+1]++;
            a3[x1][y2+1]--; a3[x2+1][y1+1]--;

            a4[x1+1][y1+1]++; a4[x2+1][y2+1]++;
            a4[x1+1][y2+1]--; a4[x2+1][y1+1]--;
        }

        // 计算前缀和
        LL ans=0;
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
            {
                a1[i][j]+=a1[i-1][j]+a1[i][j-1]-a1[i-1][j-1];
                a2[i][j]+=a2[i-1][j]+a2[i][j-1]-a2[i-1][j-1];
                a3[i][j]+=a3[i-1][j]+a3[i][j-1]-a3[i-1][j-1];
                a4[i][j]+=a4[i-1][j]+a4[i][j-1]-a4[i-1][j-1];
                ans+=c3[a1[i][j]]-c3[a2[i][j]]-c3[a3[i][j]]+c3[a4[i][j]];
                // cout<<i<<" "<<j<<" "<<ans<<endl;
            }
        cout<<ans<<endl;
    }
    return 0;
}