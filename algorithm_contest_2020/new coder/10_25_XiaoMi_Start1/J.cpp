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
int a[1005][1005],pe[1005][1005];
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int t;cin>>t;
    while(t--)
    {
        int n,m,ax,by;
        cin>>n>>m>>ax>>by;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            {
                cin>>a[i][j];
                pe[i][j]=a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1];
            }

        bool flag=true;
        for(int i=1;i<=n and flag==true;i++)
            for(int j=1;j<=m;j++)
            {
                pe[i][j]=pe[i][j]-pe[i][j-1]-pe[i-1][j]+pe[i-1][j-1];
                if(pe[i][j]==0) continue;
                if(pe[i][j]<0){
                    flag=false;
                    break;
                }
                P d2=m_p(i+ax-1,j+by-1);
                if(d2.x>n){
                    flag=false;
                    break;
                }
                if(d2.y>m){
                    flag=false;
                    break;
                }
                int value=-pe[i][j];
                pe[i][j]+=value;
                pe[d2.x+1][d2.y+1]+=value;
                pe[i][d2.y+1]-=value;
                pe[d2.x+1][j]-=value;
            }

        if(flag==true) cout<<"^_^"<<endl;
        else cout<<"QAQ"<<endl;

    }
    return 0;
}