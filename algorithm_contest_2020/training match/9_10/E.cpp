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
// 好复杂的博弈+贪心
struct node
{
    LL a1,b1,a2,b2;
    LL tag;
    node(LL a=0,LL b=0,LL c=0,LL d=0):a1(a),b1(b),a2(c),b2(d){};
    bool operator<(const node&b) const{
        return a1+b1<b.a1+b.b1;
    }
};
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    LL n;
    cin>>n;
    LL a1,b1,a2,b2;
    LL ans=0;
    priority_queue<node> que;
    for(LL i=1;i<=n;i++)
    {
        cin>>a1>>b1>>a2>>b2;
        if(a1<=b2 and b1<=a2) continue;//谁选都吃亏
        else if(a1+b1<a2+b2)//一定有一个人有净利润，他会先选
        /*这里有点迷啊*/
        {
            if(a1>b2) ans+=a1-b2;
            else ans+=a2-b1;
        }
        else//剩下的贪心选择就可以了
        {
            node tmp(a1,b1,a2,b2);
            tmp.tag=1;
            que.push(tmp);
        }
    }
    LL cnt=0;
    while(!que.empty())
    {
        
        node st=que.top();
        que.pop();
        cnt++;
        if(cnt%2==1) ans+=st.a1;
        else ans-=st.b1;

        if(st.tag==1)
        {
            st.a1=st.a2;
            st.b1=st.b2;
            st.b2=st.a2=0;
            st.tag=0;
            que.push(st);
        }
    }
    
    cout<<ans<<endl;
    return 0;
}