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

int n,d;
int fa[55];
int graph[55][55];
int dis[55];

int get_father(int x){
    return x= x==fa[x]? x:get_father(fa[x]);
}
bool unio(int x,int y){
    int a=get_father(x);
    int b=get_father(y);
    fa[a]=b;
    if(a==b) return false;
    else return true;
}

int get_dis(int &u)
{
    for(int i=1;i<=n;i++)
    {
        if(u==i) dis[i]=0;
        else dis[i]=inf;
    }
    queue<int> que;
    que.push(u);
    while(!que.empty())
    {
        int st=que.front();
        que.pop();
        for(int i=1;i<=n;i++)
        {
            if(graph[st][i]==1 and dis[st]+1<dis[i]){
                dis[i]=dis[st]+1;
                que.push(i);
            }
        }
    }
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        if(dis[i]>ans){
            ans=dis[i];
            u=i;
        }
    }
    return ans;
}

void solve()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>graph[i][j];
            // if(graph[i][j]==1 and i<=j)
            // {
            //     unio(i,j);
            // }
        }
    // 判断是否有两个块
    // bool flag=true;
    // for(int i=2;i<=n;i++)
    //     if(fa[i]!=fa[i]) flag=false;
    // if(flag==false)
    // {
    //     cout<<"-1"<<endl;
    //     return;
    // }
    // 求一条最长路径
    int u=1;
    int cnt1=get_dis(u);
    if(cnt1==inf){
        cout<<-1<<endl;
        return;
    }
    else
    {
        int cnt2=get_dis(u);
        cout<<d*cnt2<<endl;
    }
    return;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif

    solve();
    return 0;
}
