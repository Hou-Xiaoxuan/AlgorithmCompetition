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
char s[int(3e5+50)];
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
        cin>>(s+1);
        bool flag1=0,flag2=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='<') flag1=true;
            if(s[i]=='>') flag2=true;
            if(flag1==true and flag2==true) break;
        }
        if(!(flag1 and flag2)){
            cout<<n<<endl;
            continue;
        }

        int ans=0;
        for(int i=2;i<=n;i++)
        {
            if(s[i-1]=='-' or s[i]=='-') ans++;
        }
        if(s[1]=='-' or s[n]=='-') ans++;
        cout<<ans<<endl;
    }
    return 0;
}