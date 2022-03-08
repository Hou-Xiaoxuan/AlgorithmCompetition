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
    
    int n,m;
    while(cin>>n>>m)
    {
        int cnt[8]={0};
        int num[8]={0};
        num[4]=n;num[2]=n*2;
        for(int i=1;i<=m;i++){
            int x;cin>>x;
            
            cnt[4]+=x/4;
            x%=4;
            cnt[2]+=x/2;
            x%=2;
            cnt[x]++;
        }
        int tmp;
        tmp=min(num[4],cnt[4]);
        cnt[4]-=tmp;
        num[4]-=tmp;
        cnt[2]+=cnt[4]*2;
        cnt[4]=0;

        tmp=min(num[4],cnt[3]);
        cnt[3]-=tmp;
        num[4]-=tmp;
        cnt[2]+=cnt[3];
        cnt[1]+=cnt[3];
        cnt[3]=0;

        tmp=min(num[4],cnt[2]);
        num[4]-=tmp;
        cnt[2]-=tmp;
        num[1]+=tmp;
        tmp=min(num[2],cnt[2]);
        cnt[2]-=tmp;
        num[2]-=tmp;
        cnt[1]+=cnt[2]*2;
        cnt[2]=0;

        if(cnt[1]<=num[1]+num[2]+num[4]*2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
   
    return 0;
}