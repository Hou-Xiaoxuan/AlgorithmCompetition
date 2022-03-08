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
// WC，我16分钟能过掉C题，一个小时却过不掉B题？我是傻逼……

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
    
    int t;cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int> c(m+1);
        vector<P> a(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i].y;
        }
        priority_queue<P,vector<P>,greater<P>> que;
        for(int i=1;i<=m;i++){
            cin>>c[i];
            que.push(P(c[i],i));
        }
        for(int i=1;i<=n;i++) a[i].x=c[a[i].y];
        sort(a.begin()+1,a.end());
        reverse(a.begin()+1,a.end());
        LL ans=0;
        for(int i=1;i<=n;i++)
        {
            P st(inf,0);
            while(!que.empty() and que.top().y>a[i].x) que.pop();
            if(!que.empty()){
                st=que.top();
                que.pop();
            }
            ans+=min(a[i].x,st.x);
        }
        cout<<ans<<endl;
    }
    return 0;
}
