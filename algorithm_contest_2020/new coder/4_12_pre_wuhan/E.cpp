#include<bits/stdc++.h>
using namespace std;
#define  m_k make_pair
#define   P  pair<int,int>
#define  V vector
typedef long long LL;
typedef unsigned long long ULL;
//打表函数错了……只有两个解0 and 1
//LL a[]={0,1,160042,161017,396189,401104,466126,469921,1393034,1393593,6697826,6697833,52442757,52442772,1000000000000000000};
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    int t;cin>>t;
    for(int i=1;i<=t;i++)
    {
        LL n;cin>>n;
        cout<<(n>0?n-1:0)<<endl;
    }

    return 0;
}