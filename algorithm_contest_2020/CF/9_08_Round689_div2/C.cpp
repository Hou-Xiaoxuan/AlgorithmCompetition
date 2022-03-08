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
int ask(int x,int y){
    cout<<'?'<<' '<<x<<' '<<y<<endl;
    cout<<endl;
    int ret;
    cin>>ret;
    return ret;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    // 也可以双指针两端跑。
    int n;cin>>n;
    int mx=1;
    vector<int> ans(n+1);
    for(int i=2;i<=n;i++)
    {
        int tmp1=ask(mx,i);
        int tmp2=ask(i,mx);
        if(tmp1<tmp2)//a[mx]>x[i]
            ans[i]=tmp2;
        else{
            ans[mx]=tmp1;
            mx=i;
        }
        // cout<<"debug"<<mx<<endl;
    }
    ans[mx]=n;
    cout<<'!'<<' ';
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}