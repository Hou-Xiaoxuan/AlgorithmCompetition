#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define x first
#define y second 
using namespace std;
using LL=long long;
using ULL=unsigned long long;
using LD=long double;
using P=pair<int,int>;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;
//  AC

const int N=5e5+5;
//区间查询，单点修改
int a[N]={0};
LL c[N]={0};
int lowbit(int x){
    return x&(-x);
}
void update(int i,int n,int v)
{
    while(i<=N)
    {
        c[i]+=v;
        i+=lowbit(i);
    }
}

LL get_sum(int i)
{
    LL x=0;
    while(i>0)
    {
        x+=c[i];
        i-=lowbit(i);
    }
    return x;
}

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #endif

    int n;
    cin>>n;
    queue<int> que;
    LL ans=0;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        x++;//要从1计
        ans+=get_sum(n)-get_sum(x);//比x大的数量
        update(x,n,1);
        que.push(x);
    }
    cout<<ans<<endl;
    for(int k=1;k<=n-1;k++)
    {
        int val=que.front();
        que.pop();
        ans-=get_sum(val-1);//有多少比val小
        ans+=get_sum(n)-get_sum(val);//有多少比val大
        cout<<ans<<endl;
    }
    return 0;
}
