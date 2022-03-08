// https://www.luogu.com.cn/problem/U81206
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
//链式前向星的模板
const int M=8e6+5;
const int N=1e5;
int head[N],cnt=0;
struct edge{
    edge():next(0){};
    int to;
    int next;
    int value;
}edg[M];
void addEdge(int u,int v,int value){
    edg[++cnt].to=v;
    edg[cnt].value=value;
    edg[cnt].next=head[u];
    head[u]=cnt;
}
//卡的这么紧吗……
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_prictice\\in.txt","r",stdin);  
    #endif
    int n,m,k;
    //while(cin>>n>>m>>k)
    while(scanf("%d %d %d",&n,&m,&k)!=EOF)
    {
        cnt=0;
        int u,v,w;
        memset(head+1,0,sizeof(int)*n);
        for(int i=1;i<=m;i++){
            scanf("%d %d %d",&u,&v,&w);
            // cin>>u>>v>>w;
            addEdge(u,v,w);
            if(k==0) addEdge(v,u,w);
        }

        //遍历
        for(int i=1;i<=n;i++)
        {
            bool flag=false;
            for(int j=head[i];j;j=edg[j].next){
                printf("%d %d %d\n",i,edg[j].to,edg[j].value);
                // cout<<i<<" "<<edg[j].to<<" "<<edg[j].value<<endl;
                flag=true;
            }
            if(flag==false) cout<<endl;
        }

    }
    return 0;
}