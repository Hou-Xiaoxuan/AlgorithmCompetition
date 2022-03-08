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
const int N=1e5+5;
char s[N];//忘记该1e5了
// 只有我一个人没做出C题……
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
        int n,m;
        cin>>n>>m;
        cin>>(s+1);
        bool flag=true;
        int tmp1=0,tmp=0;
        for(int i=1;i<=m;i++)
            if(s[i]=='1') tmp1++;
            else if(s[i]=='?') tmp++;
        if(tmp1+tmp<m/2 or tmp1>m/2) flag=false; 
        for(int i=1;i+m<=n and flag==true;i++)
        {
            if(s[i]==s[i+m]) continue;
            else if(s[i]!='?' and s[i+m]!='?')
                flag=false;
            else if(s[i]=='?') s[i]=s[i+m];
            else if(s[i+m+1]=='?') s[i+m]=s[i];
        }
        vector<int> cnt1(n+1),cnt(n+1);
        for(int i=1;i<=n and flag==true;i++)
        {
            if(s[i]=='1') cnt1[i]=cnt1[i-1]+1;
            else cnt1[i]=cnt1[i-1];
            if(s[i]=='?') cnt[i]=cnt[i-1]+1;
            else cnt[i]=cnt[i-1];
        }
        for(int i=1;i+m-1<=n and flag==true;i++)
        {
            tmp1=cnt1[i+m-1]-cnt1[i-1];
            tmp=cnt[i+m-1]-cnt[i-1];
            if(tmp1+tmp<m/2 or tmp1>m/2)
                flag=false;
        }
        if(flag==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}