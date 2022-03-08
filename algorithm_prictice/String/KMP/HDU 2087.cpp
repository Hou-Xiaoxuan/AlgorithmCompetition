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
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin); 
    #endif
    
    while(1)
    {
        string s,p;
        cin>>s;
        if(s[0]=='#') break;
        cin>>p;
        int lenp=p.size(),lens=s.size();
        p.push_back(' ');
        vector<int> kmp(p.size()+5);
        int j=-1;
        kmp[0]=-1;
        for(int i=1;i<lenp;i++)
        {
            while(j>=0 and p[j+1]!=p[i]) j=kmp[j];
            if(p[j+1]==p[i]) j++;
            kmp[i]=j;
        }
        int ans=0;
        j=-1;
        for(int i=0;i<lens;i++)
        {
            while(j>=0 and p[j+1]!=s[i])
                j=kmp[j];
            if(p[j+1]==s[i]) j++;
            if(j==lenp-1){
                ans++;
                j=-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
