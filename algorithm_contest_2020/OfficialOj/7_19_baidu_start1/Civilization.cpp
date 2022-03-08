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
//回合数做多不超过1700……
int a[501][501];
int price[501][501];
bool vis[501][501];
int Grain=0;
int Round=0;
int n;
struct nod{
    int cnt[4]={0};
};
nod get_price(P st)//找一个最快获得下一人口的地方
{
    nod tmp;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(abs(st.x-i)+abs(st.y-j)<=3)
                tmp.cnt[a[i][j]]++;
    return tmp;
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
        int ans=inf;
        Grain=0;
        P st;
        cin>>n;
        cin>>st.x>>st.y; 
         for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>a[i][j];
        int sum=0;
         for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                {
                    if(i==st.x and j==st.y){
                        sum=0;
                        Grain+=a[st.x][st.y];
                    }
                    else sum=(abs(i-st.x)+abs(j-st.y)-1)/2+1;
                    int cnt=1;
                    nod now;
                    now.cnt[a[st.x][st.y]]++;
                    nod num=get_price(st);
                    while(cnt<9)
                    {
                        int co=now.cnt[3]*3+now.cnt[2]*2+now.cnt[1]*1;
                        int tmp=(8*cnt*cnt-Grain-1)/co+1;
                        Grain+=co*tmp;//加粮
                        sum+=tmp;//加回合
                        cnt++;//加人
                        if(num.cnt[3]){
                            num.cnt[3]--;
                            now.cnt[3]++;
                        }
                        else if(num.cnt[2]){
                            num.cnt[2]--;
                            now.cnt[2]++;
                        }
                        else if(num.cnt[1]){
                            num.cnt[1]--;
                            now.cnt[1]++;
                        }
                    }
                    ans=min(ans,sum);
                }
        cout<<ans<<endl;

    }

    return 0;
}