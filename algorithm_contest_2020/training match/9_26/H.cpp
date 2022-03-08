#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<LL,LL>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;
// 板子都忘了，鬼知道怎么RE的！
// 但是现在我想起来了，我可以的
const LL N=4e5+5;
LL b[N],a[N];
namespace A1
{
    // 只存大于0的差分
    LL c[N];
    LL lowbit(LL x){
        return x&(-x);
    }
    void update(LL x,LL n,LL value){
        while(x<=n){
            c[x]+=value;
            x+=lowbit(x);
        }
    }
    LL get_sum(LL x){
        LL ans=0;
        while(x>0){
            ans+=c[x];
            x-=lowbit(x);
        }
        return ans;
    }
}
namespace A2
{
    // 存普通差分
    LL c[N];
    void add(LL p,LL n,LL x){
        while(p<=n){
            c[p]+=x;
            p+=p&(-p);
        }
    }
    void add_range(LL l,LL r,LL n,LL x){
        add(l,n,x); add(r+1,n,-x);
    }
    LL ask(LL p){
        LL ans=0;
        while(p>0){
            ans+=c[p];
            p-= p&(-p);
        }
        return ans;
    }
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    LL t;cin>>t;
    while(t--)
    {
        memset(A1::c,0,sizeof(LL)*N);
        memset(A2::c,0,sizeof(LL)*N);
        LL n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            A2::add(i,n,a[i]-a[i-1]);
            if(a[i]-a[i-1]>0) A1::update(i,n,a[i]-a[i-1]);
        }
        while(m--)
        {
            LL flag;
            cin>>flag;
            if(flag==1)
            {
                LL l,r,k;
                cin>>l>>r>>k;
                // 先全部改成0
                LL tmp=A2::ask(l)-A2::ask(l-1);//得到第l位的差分大小
                if(tmp>0) A1::update(l,n,-tmp);//更新为0
                tmp=A2::ask(r+1)-A2::ask(r);//得到第l位的差分大小
                if(tmp>0) A1::update(r+1,n,-tmp);//更新为0

                A2::add_range(l,r,n,k);
                // 更新后位正的重新赋值
                tmp=A2::ask(l)-A2::ask(l-1);
                if(tmp>0) A1::update(l,n,tmp);
                tmp=A2::ask(r+1)-A2::ask(r);
                if(tmp>0) A1::update(r+1,n,tmp);
                
            }
            else
            {
                LL l,r;
                cin>>l>>r;
                LL ans=A1::get_sum(r)-A1::get_sum(l);//先得到l+1~r的正数和
                ans+=A2::ask(l);//在加上a[l]
                cout<<ans<<endl;
            }
            // for(int i=1;i<=n;i++) cout<<A1::get_sum(i)-A1::get_sum(i-1)<<' ';
            // cout<<endl;
            // for(int i=1;i<=n;i++) cout<<A2::ask(i)<<' ';
            // cout<<endl;
        }

    }
    return 0;
}