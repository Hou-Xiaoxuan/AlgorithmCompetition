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
const int N=1e6+5;
char s[N],ans[N];
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
        memset(s,0,sizeof(char)*(n+5));
        cin>>(s+1);
        vector<int> a(n+5);
        a[n]=1;
        for(int i=n-1;i>=1;i--)
            if(s[i]==s[i+1]) a[i]=a[i+1]+1;
            else a[i]=1;
        
        for(int i=1;i<n;i++)
        {
            if(a[i]+i-1==n) ans[i]='>';//如果知道末尾也相等,短的一点小
            else
            {
                int st=a[i]+i-1;
                ans[i]=s[st]<s[st+1]?'<':'>';
            }
        }
        ans[n]='\0';
        cout<<(ans+1)<<endl;
    }
    return 0;
}