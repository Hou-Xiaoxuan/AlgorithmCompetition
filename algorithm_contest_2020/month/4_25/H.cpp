#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
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
    
    int t;cin>>t;
    while(t--)
    {
        int N,m,a,b;cin>>N>>m>>a>>b;
        int n=m*a/b;
        int ans=0;
        ans+=a*(n/a-1);
        n=n%a+a;
        m-=(ans*b/a);
        if(b>a)
        {
            int tmp=b/a;
            b-=tmp*a;
            m-=n*tmp;
        }
        vector<int> pe(b+1),pt(b+1);
        pe[b]=n;
        while(m--)
        {
            int cnt=b;
            for(int i=b;i>=1 and cnt;i--)
                if(pe[i]>=cnt){
                    pt[i-1]+=cnt;
                    pe[i]-=cnt;
                    cnt=0;
                }
                else{
                    pt[i-1]+=pe[i];
                    pe[i]=0;
                    cnt-=pe[i];
                }
            for(int i=0;i<=b;i++)
                pe[i]+=pt[i],pt[i]=0;
        }
        ans+=pe[0];
        cout<<ans<<endl;
    }

    return 0;
}