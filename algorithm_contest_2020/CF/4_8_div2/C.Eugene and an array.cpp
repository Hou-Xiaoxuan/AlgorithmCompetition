#include<bits/stdc++.h>
using namespace std;
#define  m_k make_pair
#define   P  pair<long long,int>
#define  V vector
typedef long long LL;
typedef unsigned long long ULL;
//补题：前缀和+标记+尺取
//Although use prelix sum, it's used with take
//int a section (l,r],(a[l-1]==r),we add the a[r],a[r]+a[r-1]……a[r]+……a[l+1],sum is r-l;
int main()
{
    int n;
    while(cin>>n)
    {
        vector<LL> a(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i]+=a[i-1];
        }
        map<LL,bool> vis;
        vis[0]=true;
        int l=0,r=1;
        LL ans=0;
        while(r<=n)
        {
            while(vis[a[r]])//a[i] appeared before,look for it;
            {
                vis[a[l]]=false;// l~r just a[r] is repeate
                l++;//period until a[l-1]=a[r]; 
            }//now ,[l,r]is good;
            vis[a[r]]=true;
            ans+=r-l;
            r++;
        }
        cout<<ans<<endl;
    }
    return 0;
}