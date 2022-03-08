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

// 补题 AC
// 啊，知道我错在哪里了，不必局限于只染一条边啊
// 这道题不是不断在一个图上增加颜色，而是只要有k种颜色组成就可以了
// 因此只要贪心的找最大权值的顶点就可以了，不必在意他是不是边缘点，因为可以将他值到边缘的边全部染成一个颜色
// 这样结果仍然只增加了该顶点的权值(被多染的一部分贡献的权值并没有改变)
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif

    // 只使用度数就可以了
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        vector<int> deg(n+1);
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
            deg[u]++;
            deg[v]++;
        }
        vector<int> order;
        // 点i的权重被增加的最多的次数为其deg[i]-1
        LL ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<deg[i];j++)
                order.push_back(a[i]);
            ans+=a[i];
        }
        // 不用考虑是不是边缘的情况，暴力加就可以了
        
        sort(order.begin(),order.end(),[](const int& x,const int& y)->bool{return x>y;});
        cout<<ans<<" ";
        for(auto v:order){
            ans+=v;
            cout<<ans<<' ';
        }cout<<endl;
    }
    return 0;
}
