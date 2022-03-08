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

const int N=1010;
int sg[N];
bool vis[N];
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_prictice\\in.txt","r",stdin); 
    #endif
    

    sg[0]=0;
    for(int i=1;i<=1005;i++)
    {
        memset(vis,0,sizeof(vis));
        for(int j=0;i-(1<<j)>=0;j++)
            vis[sg[i-(1<<j)]]=1;
        for(int j=0;j<=1005;j++)
        {
            if(vis[j]==false) {sg[i]=j;break;}
        }
    }
    int n;
    while(cin>>n)
    {
        if(sg[n]!=0) cout<<"Kiki"<<endl;
        else cout<<"Cici"<<endl;

    }

    return 0;
}