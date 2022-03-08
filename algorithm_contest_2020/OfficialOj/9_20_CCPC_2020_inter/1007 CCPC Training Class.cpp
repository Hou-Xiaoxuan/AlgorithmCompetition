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
char s[int(1e5+5)];
int cnt[30];
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int t; cin>>t;
    for(int k=1;k<=t;k++)
    {
        cin>>(s+1);
        int n=strlen(s+1);
        sort(s+1,s+n+1);
        memset(cnt,0,sizeof(cnt));
        int ans=0;
        for(int i=1;i<=n;i++){
            cnt[s[i]-'a']++;
            ans=max(ans,cnt[s[i]-'a']);
        }
        cout<<"Case #"<<k<<": "<<ans<<endl;
    }
    return 0;
}