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
//优化了半天，有必要吗？呵呵，以后不管什么题，先莽上去再说
void getname(string &a,string &s,LL k){
    for(int i=k-1;s[i]!='/';i--)
        a.push_back(s[i]);
}
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
        map<string,pair<int,int> > ma;
        
        string s;
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            LL k=s.find('.',0);;
            while(k!=-1)
            {
                if(s[k+1]=='e' and s[k+2]=='o' and s[k+3]=='j'){
                    string a;
                    getname(a,s,k);
                    ma[a].x++;
                    if(k+4==int(s.size()))
                        ma[a].y++;
                }
                k=s.find('.',k+1);
            }
        }
        int ans=0;
        for(auto i:ma)
            if(i.second.x==1 or (i.second.y>1)) ans++;//只出现过一次 or 在末尾出现过两次
        cout<<ans<<endl;
    }
    return 0;
}