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
// 学到了，学到了，还能这么玩啊。。
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int n;cin>>n;
    LL cnt[65][65]={0};
    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        LL val;
        double x;
        cin>>x;
        val=llround(x*1e9);//不丢失精度的转换成最接近的LL型
        int cnt2=0,cnt5=0;
        while(val%2==0){
            cnt2++;
            val/=2;
        }
        while(val%5==0){
            cnt5++;
            val/=5;
        }
        for(int i=0;i<=64;i++)
            for(int j=0;j<=64;j++)
            {
                if(i+cnt2>=18 and j+cnt5>=18)
                    ans+=cnt[i][j];
            }
        cnt[cnt2][cnt5]++;
    }
    cout<<ans<<endl;
    return 0;
}