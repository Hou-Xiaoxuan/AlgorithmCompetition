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
const int N=1e6+5;
int du[N];//联通节点的度
LL number[N];//答案包含i的个数
int head[N],tot=0;
struct Edg{
    int to;
    int next;
    int value;
    Edg(int a=0,int b=0,int c=0):to(a),next(b),value(c){};
}edg[N<<1];
void add(int u,int v){
    edg[++tot]=Edg(v,head[u]);
    head[u]=tot;
}

bool check[N];//是否和n联通
vector<int >all_s[N];//储存所有的序列（如果存在的话）
queue<int> que;//储存末端节点

int readint()//快读板子
{
    char ch;int i=0,f=1;
    for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
    if(ch=='-') {ch=getchar();f=-1;}
    for(;ch>='0'&&ch<='9';ch=getchar()) i=(i<<3)+(i<<1)+ch-'0';
    return i*f;

}
void bfs(int u)
{
    queue<int> qu;
    qu.push(u);
    check[u]=true;
    while(!qu.empty())
    {
        u=qu.front();
        qu.pop();
        for(int e=head[u];e;e=edg[e].next)
        {
            int v=edg[e].to;
            du[v]++;
            if(check[v]==false)
            {
                check[v]=true;
                qu.push(v);
            }
        }
    }
}
void tuopu(int u)
{
    queue<int> qu;
    qu.push(u);
    number[u]=1;
    while(!qu.empty())
    {
        u=qu.front();
        qu.pop();
        if(head[u]==0){
            //head=0说明这里是末端节点
            que.push(u);
            continue;
        }
        for(int e=head[u];e;e=edg[e].next)
        {
            int v=edg[e].to;
            du[v]--;
            number[v]+=number[u];
            if(du[v]==0) qu.push(v);
        }

    }

}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int t; t=readint();
    while(t--)
    {
        int n; n=readint();
        for(int i=1;i<=n;i++)
        {
            int k=readint();
            if(k==1)
            {
                int m=readint();
                int x;
                for(int j=1;j<=m;j++)
                {
                    x=readint();
                    all_s[i].emplace_back(x);
                }
            }
            else
            {
                int x,y;
                x=readint();
                y=readint();
                add(i,x);
                add(i,y);
            }
        }

        bfs(n);//标记联通节点
        tuopu(n);//排序

        LL sum=0;
        map<int,LL> ma;
        while(!que.empty())
        {
            int u=que.front();
            que.pop();
            LL size=all_s[u].size();
            sum+=size*(number[u]);
            for(int i=0;i<size;i++)
                ma[all_s[u][i]]+=number[u];
        }
        LL maxn=-1;
        for(auto i:ma)
            maxn=max(maxn,i.second);
        printf("%lld\n",maxn*2<=sum?sum:2*(sum-maxn));
        for(int i=1;i<=n;i++)
            all_s[i].clear();
        memset(head,0,sizeof(int)*(n+1));
        memset(number,0,sizeof(LL)*(n+1));
        memset(check,0,sizeof(bool)*(n+1));
    }
    return 0;
}