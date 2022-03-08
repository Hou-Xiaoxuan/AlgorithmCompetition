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
        for(int i=1;i<=m;i++){
            int x;cin>>x;
            n-=x/8;
            x%=8;
            if(x==7){cnt[4]++;cnt[2]++; cnt[1]++; }
            else if(x==6){ cnt[4]++;cnt[2]++; }
            else if(x==5){ cnt[4]++;cnt[1]++; }
            else if(x==3){ cnt[2]++;cnt[1]++;}
            else cnt[x]++;
        }
        num[4]=n;
        num[2]=2*n;
        // 4-4
        if(cnt[4]<=num[4]){
            num[4]-=cnt[4];
            cnt[4]=0;
        }
        else
        {
            cnt[4]-=num[4];
            num[4]=0;
            cnt[2]+=cnt[4]*2;
            cnt[4]=0;
        }
        
        // // 3-4
        // if(cnt[3]<=num[4]){//有足够的4座
        //     num[4]-=cnt[3];
        //     cnt[3]=0;
        // }
        // else{//4座不够
        //     cnt[3]-=num[4];
        //     num[4]=0;//先用完4座
        //     cnt[2]+=cnt[3];
        //     cnt[1]+=cnt[3];
        //     cnt[3]=0;//拆分成2座和1座
        // }
        // 2-4
        if(cnt[2]<=num[4]){
            num[4]-=cnt[2];
            num[1]+=cnt[2];
            cnt[2]=0;
        }
        else {
            cnt[2]-=num[4];
            num[1]+=num[4];
            num[4]=0;
        }
        // 2-2
        if(cnt[2]<=num[2]){
            num[2]-=cnt[2];
            cnt[2]=0;
        }
        else{
            cnt[2]-=num[2];
            num[2]=0;
            cnt[1]+=cnt[2]*2;
            cnt[2]=0;
        }
        // 1
        if(cnt[1]<=num[1]+num[2]+num[4]*2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
 
    }
    return 0;
}