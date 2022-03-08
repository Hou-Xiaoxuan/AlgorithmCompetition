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
//WC,这么暴力的吗？什么优化都不用，就过了？？？？
int main()
{
        IOS;
        #ifdef _DEBUG
        freopen("D:\\CODE\\code_contest\\out.txt","w",stdout);
        freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);  
        #endif

    int n;
    while(cin>>n)
    {
        // vector<string> a;
        // for(int i=1;i<=n;i++)
        // {
        //     cin>>s;
        //     int k=s.size()-1;
        //     if(k>3 and s[k]=='j' and s[k-1]=='o' and s[k-2]=='e' and s[k-3]=='.')
        //         a.push_back(s);
        // }
        // sort(a.begin(),a.end());
        // int ans=a.size();
        // for(int i=0;i<int(a.size())-1;i++){
        //     if(a[i+1].find(a[i])!=string::npos)
        //         ans--;
        // }
        // cout<<ans<<endl;
        vector<string> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a.begin()+1,a.end());
        int ans=0;
        a.push_back("***");
        for(int i=1;i<=n;i++){
            int k=a[i].size()-1;
            if(k<3) continue;
            string &s=a[i];
            if(s[k]=='j' and s[k-1]=='o' and s[k-2]=='e' and s[k-3]=='.')
                if(a[i+1].find(s)==string::npos)
                    ans++;
        }
        
        cout<<ans<<endl;
    }

    return 0;
}