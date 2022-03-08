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
// 赌一手暴力dfs
bool exist[505][505];
int sum[505][505];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
// 很神奇的BFS复杂度
// DFS还是不行,另外，读题失误，还是要英文题面啊
// 每个点的离开会影响到与它相邻的点的坐标，这样更新就可以了。
// 比较难的是想到开始初始化为到断电的曼哈顿距离(没有点离开的答案)
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int n;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                exist[i][j]=1;
                sum[i][j]=min(min(i,n-i+1),min(j,n-j+1));
            }
        int ans=0;
        for(int i=1;i<=n*n;i++)
        {
            int p;
            cin>>p;
            P st((p-1)/n+1,(p-1)%n+1);
            ans+= --sum[st.x][st.y];
            exist[st.x][st.y]=0;
            deque<P> que;
            // 双端队列BFS我傻了
            que.push_back(st);
            while(!que.empty())
            {
                st=que.front();
                que.pop_front();
                for(int i=0;i<4;i++)
                {
                    P to(st.x+dx[i],st.y+dy[i]);
                    if(to.x<1 or to.x>n or to.y<1 or to.y>n) continue;
                    // 只有能更新的点才会放入que，而每个点开始的值最大为n，每个点最多放入n次，复杂度n^3
                    if( sum[to.x][to.y] > sum[st.x][st.y] + exist[to.x][to.y] )
                    {
                        sum[to.x][to.y] = sum[st.x][st.y] + exist[to.x][to.y];
                        // 
                        if(exist[to.x][to.y]) que.push_back(to);
                        else que.push_front(to);
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
