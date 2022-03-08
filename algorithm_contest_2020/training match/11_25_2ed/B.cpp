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

// WA on test 52 就离谱
// 应该是有特殊情况，什么特殊情况呢？
// 贪心应该是最优策略啊……
// 难道不是贪心吗？？
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif

    LL n;
    while(cin>>n)
    {
        LL c,d;
        cin>>c>>d;
        vector<int> a(n+2);
        for(int i=1;i<=n;i++) cin>>a[i];
        a[n+1]=inf;
        // sort(a.begin()+1,a.end());
        //*离谱！！为什么加上排序就tm WA在44了？？
        //*排序，把a[n+1]=1e9+7,改成int型，WA在52
        //*不排序，LL,a[n+1]=1e15,WA在44
        LL value=0,cnt=0;//代表已经积累了缩少个和多少代价
        LL ans=0;
        for(int i=1;i<=n;i++)//每个点可以清理或不清理，取决于下一个点的代价
        {
            if(i==n){
                ans+=c+value;
                break;
            }
            LL cost=LL(a[i+1]-a[i])*(cnt+1)*d+value;//叠加到下一个点的代价
            if(cost<c and cost>0){//*很神奇，这里改成<=就WA了//cost>0
                cnt++;
                value+=LL(a[i+1]-a[i])*cnt*d;
                continue;
            }
            else{
                ans+=c+value;
                cnt=0;
                value=0;
            }
        }
        // ans+=c+value;
        cout<<ans<<endl;
    }
    return 0;
}
