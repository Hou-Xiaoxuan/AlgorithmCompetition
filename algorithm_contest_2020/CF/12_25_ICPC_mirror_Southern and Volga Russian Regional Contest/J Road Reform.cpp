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
const LL inf=0x3f3f3f3f;

// 魔改最小生成树的kruskal算法
const LL N=2e5+8;
LL fa[N];
struct Edge
{
    LL u;
    LL v;
    LL value;
    bool operator <(const Edge & s){
        return this->value<s.value;
    } 
};
// 并查集部分
LL get_father(LL x){
    return fa[x]= x==fa[x]? x:get_father(fa[x]);
}
bool unio(LL x,LL y){
    LL a=get_father(x);
    LL b=get_father(y);
    fa[a]=b;
    if(a==b) return false;
    else return true;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif

    LL t; cin>>t;
    while(t--)
    {
        LL n,m,k;
        cin>>n>>m>>k;
        vector<Edge> edgl(m+1),edgr(m+1);
        LL totl=0,totr=0;
        LL u,v,w;
        LL cnt=n;
        for(LL i=1;i<=n;i++) fa[i]=i;
        LL max_left=0;
        LL min_right=inf;
        for(LL i=1;i<=m;i++)
        {
            cin>>u>>v>>w;
            if(w<=k){
                if(unio(u,v)==true)   cnt--;
                // edgl.push_back(Edge());
                totl++;
                edgl[totl].u=u;
                edgl[totl].v=v;
                edgl[totl].value=w;
                max_left=max(max_left,w);
            }
            else{
                // edgr.push_back(Edge());
                totr++;
                edgr[totr].u=u;
                edgr[totr].v=v;
                edgr[totr].value=w;
                min_right=min(min_right,w);
            }
        }
        // sort(edgl.begin(),edgl.begin()+totl+1);
        
        if(cnt>1)
        {
            sort(edgr.begin(),edgr.begin()+totr+1);
            LL ans=0;
            for(LL i=1;i<=totr;i++)
            {
                if(unio(edgr[i].u,edgr[i].v)==true)
                {
                    ans+=edgr[i].value-k;
                    cnt--;
                }
                if(cnt==1) break;
            }
            cout<<ans<<endl;
        }
        else
        {
            cout<<min(abs(max_left-k),abs(k-min_right))<<endl;
        }
    }
    return 0;
}
