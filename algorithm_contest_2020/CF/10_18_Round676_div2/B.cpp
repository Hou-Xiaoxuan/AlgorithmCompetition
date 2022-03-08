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
char a[205][205];
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
        int n;cin>>n;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>a[i][j];
        queue<P> ans;
        if(a[2][1]==a[1][2])
        {
            if(a[n][n-1]==a[2][1]) ans.push(m_p(n,n-1));
            if(a[n-1][n]==a[2][1]) ans.push(m_p(n-1,n));
        }
        else if(a[n][n-1]==a[n-1][n])
        {
            if(a[2][1]==a[n][n-1]) ans.push(m_p(2,1));
            if(a[1][2]==a[n][n-1]) ans.push(m_p(1,2));
        }
        else
        {
            char ch=a[2][1];
            if(a[1][2]!=ch) ans.push(m_p(1,2));
            if(a[n][n-1]==ch) ans.push(m_p(n,n-1));
            if(a[n-1][n]==ch) ans.push(m_p(n-1,n));
        }
        cout<<ans.size()<<endl;
        while(!ans.empty()){
            cout<<ans.front().x<<" "<<ans.front().y<<endl;
            ans.pop();
        }
    }
    return 0;
}