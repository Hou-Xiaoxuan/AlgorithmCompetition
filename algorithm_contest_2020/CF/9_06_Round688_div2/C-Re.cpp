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
char s[int(3e5+5)];
// 以后少用这种模拟的思路
// 把一步一步推导的过程直接得出结论，就是 a[i]=a[i+k]
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

        for(int i=1;i<=m and flag==true;i++)
        {
            char ch='?';
            for(int j=i;j<=n and flag==true;j+=m)
            {
                if(s[j]=='?') continue;
                if(ch=='?')
                    ch=s[j];
                else
                {
                    if(ch==s[j]) continue;
                    else flag=false;
                }        
            }
            if(flag==true)
                for(int j=i;j<=n;j+=m)
                    s[j]=ch;
        }
        tmp1=tmp=0;
        for(int i=1;i<=m;i++)
            if(s[i]=='1') tmp1++;
            else if(s[i]=='?') tmp++;
        if(tmp1+tmp<m/2 or tmp1>m/2) flag=false;
        if(flag==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}