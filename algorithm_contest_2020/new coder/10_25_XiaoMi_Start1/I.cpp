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
bool vis[1005][1005];
char graph[1005][1005];
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>graph[i][j];

    queue<P > que;
    for(int i=1;i<=n;i++)
    {
        if(graph[i][1]=='A') {vis[i][1]=true; que.push(m_p(i,1));}
        if(graph[i][m]=='D') {vis[i][m]=true; que.push(m_p(i,m));}
    }
    for(int j=1;j<=m;j++)
    {
        if(graph[1][j]=='W') {vis[1][j]=true; que.push(m_p(1,j));}
        if(graph[n][j]=='S') {vis[n][j]=true; que.push(m_p(n,j));}
    }
    while(!que.empty())
    {
        P st=que.front();
        que.pop();
        if(st.x+1<=n and graph[st.x+1][st.y]=='W'){
            vis[st.x+1][st.y]=true;
            que.push(m_p(st.x+1,st.y));
        }
        if(st.x-1>=1 and graph[st.x-1][st.y]=='S'){
            vis[st.x-1][st.y]=true;
            que.push(m_p(st.x-1,st.y));
        }
        if(st.y-1>=1 and graph[st.x][st.y-1]=='D'){
            vis[st.x][st.y-1]=true;
            que.push(m_p(st.x,st.y-1));
        }
        if(st.y+1<=m and graph[st.x][st.y+1]=='A'){
            vis[st.x][st.y+1]=true;
            que.push(m_p(st.x,st.y+1));
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(vis[i][j]==true)
                ans++;
    cout<<ans<<endl;
    return 0;
}