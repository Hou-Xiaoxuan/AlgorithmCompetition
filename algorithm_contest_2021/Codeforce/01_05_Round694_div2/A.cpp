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
// AC
// 不开LL是SB

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #elif _LINUX
    freopen("/media/linxuan/储存/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("/media/linxuan/储存/CODE/algorithm_contest/in.txt","r",stdin);
    #endif
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        LL ans[2]={0};
        //最大答案不会发生改变，合并只能减小答案。
        vector<int> a(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ans[0]+=(a[i]-1)/x+1;
            ans[1]+=a[i];
        }
        cout<<(ans[1]-1)/x+1<<" "<<ans[0]<<endl;

    }
    return 0;
}
