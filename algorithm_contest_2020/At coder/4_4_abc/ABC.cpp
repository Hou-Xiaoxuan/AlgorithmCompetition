#include<bits/stdc++.h>
using namespace std;
#define  m_k make_pair
#define   P  pair<int,int>
#define  V vector
typedef long long LL;
typedef unsigned long long ULL;
void solve_B()
{
    int n,m;
    while(cin>>n>>m)
    {
        vector<int> a(n+1);
        double sum=0;
        for(int i=1;i<=n;i++)
            cin>>a[i],sum+=a[i];
        sum/=(4*m);
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(a[i]>=sum) cnt++;
        if(cnt>=m) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

}
void solve_C()
{
    ULL n,k;
    while(cin>>n>>k)
    {
        if(n==0){
            cout<<0<<endl;
            continue;
        }
    ULL ans=min(n%k,k-n%k);
    cout<<ans<<endl;
    }
}
int main()
{
    //freopen("D:\\CODE\\code_contest\\in.txt","w",stdout);
    //freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);  
    solve_C();
    return 0;
}