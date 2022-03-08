#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
#define m_p make_pair
#define x first
#define y second
pair<int,int >dot[15];
const int inf=0x3f3f3f3f;
int edg[15][15];
bool vis[15];
int n,ans,sum;
void dfs(int k, int st)
{
    if(sum>ans) return;
    if(k==n-1) {
        for(int i=1;i<=n;i++)
            if(vis[i]==false)
                {
                    sum+=edg[st][i];
                    ans=min(ans,sum);
                    sum-=edg[st][i];
                }
        
    }

    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false)
        {
            vis[i]=true;
            sum+=edg[st][i];
            dfs(k+1,i);
            vis[i]=false;
            sum-=edg[st][i];
        }
    }
}
int main()
{

    #ifdef _DEBUG
    freopen("D:\\CODE\\Temp\\out.txt","w",stdout);
    freopen("D:\\CODE\\Temp\\in.txt","r",stdin);  
    #endif
    int t; cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>dot[i].x>>dot[i].y;
            vis[i]=false;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                edg[i][j]=abs(dot[i].x-dot[j].x)+abs(dot[i].y-dot[j].y);
        ans=inf;sum=0;
        for(int i=1;i<=n;i++){
            vis[i]=true;
            dfs(1,i);
            vis[i]=false;
        }
        cout<<ans<<endl;
    }
    return 0;
}