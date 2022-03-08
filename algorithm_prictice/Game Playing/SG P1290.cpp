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
// 题解链接（SG函数的推导过程）：https://www.luogu.com.cn/blog/user17702/solution-p1290

bool get_sg(int n,int m)
{
    if(m==0) return 0;
    if(n/m==1) return !get_sg(m,n%m);
    return 1;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_prictice\\in.txt","r",stdin); 
    #endif
    
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;
        if(n<m) swap(n,m);
        if(get_sg(n,m)) cout<<"Stan wins"<<endl;
        else cout<<"Ollie wins"<<endl;

    }

    return 0;
}