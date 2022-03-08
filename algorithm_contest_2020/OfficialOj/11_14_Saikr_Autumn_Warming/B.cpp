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
// DP,使用单调队列维护更新
// LL f[2005][2005]; //f[i][j]是选择i,共k个时的最大值
// deque<pair<LL,int> > que[2005]; //que[i]选k个时，维护到a[i]的单调队列
// 卧槽，过了
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<LL> > f(n+1,vector<LL>(m+1));
    vector<deque<pair<LL,int> > > que(m+1);
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=k;i++) f[i][1]=a[i];
    for(int i=2;i<=n;i++)
    {
        while(!que[1].empty() and que[1].back().x<=f[i-1][1]) que[1].pop_back();
        que[1].push_back(m_p(f[i-1][1],i-1));
        // 弹出超出i-k+1~i范围的数据
        for(int j=1;j<=m;j++)
            while(!que[j].empty() and que[j].front().y<i-k)
                que[j].pop_front();
        for(int j=2;j<=min(i,m);j++)
        {
            // if(que[j-1].empty()) continue;//如果没有可以选择的点，跳过
            // 有的话，更新
            if(que[j-1].front().x>0) f[i][j]=que[j-1].front().x+a[i];//**=0的话绝对不能更新
        }
        for(int j=2;j<=min(i,m);j++)
        {
            // 新元素入列，维护
            while(!que[j].empty() and que[j].back().x<=f[i][j]) que[j].pop_back();
            que[j].push_back(m_p(f[i][j],i));
        }
    }
    LL ans=0;
    for(int i=n-k + 1;i<=n;i++) ans=max(ans,f[i][m]);//**选择范围
    cout<<ans<<endl; 
    return 0;
}
