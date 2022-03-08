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

// 贪心的策略是不行的
// 伪DP WA on test 34
// 考虑所有的分组依旧 WA on test 34
// 考虑更多的分组，几乎是所有的分组了吧，依旧是34
// 忽略了n=1的情况，现在这个程序也跑到52了，cnm的52

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
        cin>>d>>c;
        vector<LL> a(n+2);
        for(int i=1;i<=n;i++) cin>>a[i];
        a[n+1]=1e18;
        // 求出每个清理片段的覆盖范围与代价
        vector<vector<pair<int,int> > > cost(n+1);//cost[i]为覆盖到x点，代价为y
        for(int i=1;i<=n;i++) cost[i].push_back(P(i,d));
        for(int i=1;i<=n;i++)
        {
            LL value=0,cnt=0;
            for(int j=i;j<=n;j++)
            {
                LL num=(a[j+1]-a[j])*(cnt+1)*c+value;
                if(num<d){
                    cnt++;
                    value+=cnt*c*(a[j+1]-a[j]);
                    if(value<0) break;//特判
                    cost[i+cnt].push_back(P(i,value+d));
                    continue;
                }
                else{
                    break;
                }
            }
        }
        vector<LL> sum(n+1);//如果在i点执行清理的最小答案
        sum[1]=d;
        for(int i=2;i<=n;i++)
        {
            sum[i]=sum[i-1]+d;
            for(int j=0;j<(int)cost[i].size();j++)
                sum[i]=min(sum[i],sum[cost[i][j].x-1]+cost[i][j].y);
            // sum[i]=min(sum[i-1]+d,sum[cost[i].x-1]+cost[i].y);
        }
        cout<<sum[n]<<endl;//最后一个点n一定会执行清理
    }
    return 0;
}
