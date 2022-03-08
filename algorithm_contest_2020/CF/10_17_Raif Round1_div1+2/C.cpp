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
char s[int(2e5+5)];
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
        cin>>(s+1);
        int n=strlen(s+1);
        stack<char> sta;
        sta.push(s[1]);
        for(int i=2;i<=n;i++)
        {
            if(s[i]=='B' and !sta.empty()) sta.pop();
            else sta.push(s[i]);
        }
        cout<<sta.size()<<endl;
    }
    return 0;
}