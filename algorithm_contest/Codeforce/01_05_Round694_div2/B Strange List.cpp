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
// 不开LL的SB

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
        LL ans=0;
        vector<LL> a(n+1),num(n+1,1);
        pair<LL,LL> min_ct(0,inf);//位置和大小
        for(int i=1;i<=n;i++)
        {
            int val;cin>>val;
            a[i]=val;
            while(val%x==0){
                num[i]++;
                val/=x;
            }
            //只有当无法继续除x且不为1的时候，才算终止。
            if(num[i]<min_ct.y) min_ct=P(i,num[i]);
        }
            for(int i=1;i<=n;i++)
            {
                if(i<min_ct.x) ans+=a[i]*(min_ct.y+1);//在index前面的能被多访问
                else ans+=a[i]*(min_ct.y);
                // 这里相乘不会爆int 吧……
            }
        
        cout<<ans<<endl;
    }
    return 0;
}
