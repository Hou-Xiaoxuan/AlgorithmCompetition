#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;
int a[1005][1005];
int color[205][205];
int dx[]={0,0,1,-1,0};
int dy[]={0,-1,0,0,1};
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);  
    #endif
    
    int m,n;
    cin>>n>>m;
    int cnt=1;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        cin>>a[i][j];
    }
    for(int i=0;i<=200;i++)
    for(int j=0;j<=200;j++)
        if(i==j) color[i][j]=0;
        else color[i][j]=inf;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        for(int k=1;k<=4;k++)
            if(a[i][j]!=a[i+dx[k]][j+dy[k]])
                color[a[i][j]][a[i+dx[k]][j+dy[k]]]=1;
    for(int i=1;i<=200;i++)
        for(int j=1;j<=200;j++)
            for(int k=1;k<=200;k++)
                color[j][k]=min(color[j][k],color[j][i]+color[i][k]);
    
    int t;cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<color[a][b]<<endl;

    }

    return 0;
}