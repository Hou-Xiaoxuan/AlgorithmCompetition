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
const int M=4e5+5;
const int N=1e5;
vector<P > edg[N];
// 神奇的贪心思路：
// https://blog.csdn.net/caowenbo2311694605/article/details/90675774?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.add_param_isCf&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.add_param_isCf
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        for(int i=1;i<=n;i++) edg[i].clear();
        int u,v,val;
        for(int i=1;i<n;i++){
            cin>>u>>v>>val;
            edg[u].emplace_back(m_p(v,val));
            edg[v].emplace_back(m_p(u,val));
        }
        
        for(int i=1;i<=n;i++)
            sort(edg[i].begin(),edg[i].end(),[](P &a,P &b){
                return a.y<b.y;
            });
        LL ans=0;
        for(int i=1;i<=n;i++)
        {
            if(edg[i].size()>1)
            {
                bool flag=false;
                for(auto j:edg[i])
                {
                    if(flag==false){
                        flag=true;
                        ans+=j.second*LL(edg[i].size()-1);
                    }
                    else ans+=LL(j.second);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}