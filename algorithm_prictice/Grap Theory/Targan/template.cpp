//http://acm.hdu.edu.cn/showproblem.php?pid=3478
#include<math.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<cstring>
#include<cstdio>
#include<queue>
#include<stack>
#include <iso646.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;
//先是一堆莫名其妙的MLE，然后就开始TLE……我的并查集的板子又出锅了！！
//二分图匹配： 主要就是染色，如果发生矛盾，就不是二分图
//对于这道题，如果是二分图 就是No，否则就是Yes
const int N=1e5+5;
vector<int> edge[N];
int color[N];
// 并查集判断是否联通
int fa[N];
int get_father(int x){
    if(fa[x]==x) return x;
    return fa[x]=get_father(fa[x]);
}
void unio(int x,int y){
    int a=get_father(x);
    int b=get_father(y);
    if(a!=b) fa[a]=b;
}
bool jungle(int xx,int col)
{
    
    for(int i=0;i<edge[xx].size();i++)
    {
        int yy=edge[xx][i];
        if(color[xx]==color[yy]) 
            return false;
        if(color[yy]==0)
        {
            color[yy]=3-col;
            if(jungle(yy,3-col)==false)
                return false;        
        }
    }
    return true;
}

int main()
{
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_prictice\\in.txt","r",stdin);  
    #endif
    
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        int n,m,s;
        scanf("%d %d %d",&n,&m,&s);
        memset(color,0,sizeof(int)*(n+1));
        for(int i=0;i<n;i++){
            fa[i]=i;
            edge[i].clear();
        }
        int u,v;
        for(int i=1;i<=m;i++){
            scanf("%d %d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
            unio(u,v);
            // addEdge(u,v);
        }

        int cnt=0;
        for(int i=0;i<n;i++)
            if(fa[i]==i) {
                cnt++;
            }
        if(cnt>2){
            //cout<<"Case "<<k<<": "<<"NO"<<endl;
            printf("Case %d: NO\n",k);
            continue;
        }
        color[s]=1;
        if(jungle(s,1)==true){
            printf("Case %d: NO\n",k);
            continue;
        }
        
        printf("Case %d: YES\n",k);
    }

    return 0;
}