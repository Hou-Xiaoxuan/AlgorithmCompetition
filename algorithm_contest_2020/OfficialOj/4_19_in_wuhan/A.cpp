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
        int n,m;cin>>n>>m;
        vector<LL> a(n+1);
        int cnt=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i!=1 and a[i]==a[1]) cnt++;
        }
        int s=a[1]+1;
        a[1]++; m--;
        sort(a.begin()+1,a.end());
        int k=lower_bound(a.begin()+1,a.end(),s)-a.begin();
    //printf("y\n");
        if(n-cnt-1>=m)
            cout<<n-k+1<<endl;
        else
        {   
    //printf("yy\n");
            m-=(n-cnt-1);
            cout<<n-k+1+min(cnt,m)<<endl;
        }
    }
    return 0;
}