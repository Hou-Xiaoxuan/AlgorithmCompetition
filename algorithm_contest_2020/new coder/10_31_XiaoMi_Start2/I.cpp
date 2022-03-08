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
// 能卡过真不容易
string s,t;
int f[2005][2005];//从i位和j位开始构造出答案需要删除多少个
int solve()
{
    memset(f,0,sizeof(f));
    int lens=s.size(),lent=t.size();
    s.push_back('0');
    for(int i=lens;i>=0;i--)
        for(int j=lent-1;j>=0;j--)
        {
            if(s[i]<t[j])
                f[i][j]= lens+lent-i-j;
            else if(s[i]==t[j])
                f[i][j] = max( f[i+1][j+1]+2,max(f[i][j+1],f[i+1][j]) );
            else if(s[i]>t[j])
                f[i][j]=max(f[i+1][j],f[i][j+1]);
        }
    return f[0][0];
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    while(cin>>s>>t)
    {
        cout<<solve()<<endl;
    }
    return 0;
}