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
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);  
    #endif

    int n,k;
    while(cin>>n>>k)
    {
        vector<char>s(n+1);
        for(int i=1;i<=n;i++)
            s[i]=char(i%24+2+'a');//c~z
        
        s[1]='b';//只有这一个是以b开头
        for(int i=0;i<k-1;i++){
            s[n-i]='a';
        }
        for(int i=1;i<=n;i++) cout<<s[i];
        cout<<endl;
    }
    return 0;
}