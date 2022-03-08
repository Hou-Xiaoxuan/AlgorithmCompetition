#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;

int ia[105];
int ib[105];
int ic[105];
int n;
int get_c(int,int);
int get_b(int a)
{

    int ans=inf;
    for(int i=1;i<=n;i++){
        int tmp=get_c(a,i);
        ans=min(tmp,ans);
    }
    return ans;
}
int get_c(int a,int b)
{
    int ans=inf;
    for(int i=1;i<=n;i++)
    {
        if(abs(ia[a]+ib[b]+ic[i])<=abs(ans)){
            ans=ia[a]+ib[b]+ic[i];
        //printf("%d %d %d   %d\n",a,b,i,ans);
        }
    }

    return ans;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);  
    #endif
    
    cin>>n;
    for(int i=1;i<=n;i++) cin>>ia[i];
    for(int i=1;i<=n;i++) cin>>ib[i];
    for(int i=1;i<=n;i++) cin>>ic[i];
    
    int ans=-inf;
    for(int i=1;i<=n;i++){
        int tmp=get_b(i);
        if(ans<tmp) ans=tmp;
    }
    cout<<ans<<endl;
    return 0;
}