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
const int N=1e5+10;
bool vis[N];
vector<P > cnt[100005];
vector<int> sum[100005];
// map<int,int> pre[100005];
// 补题
// 题解：转换思路，存素数a在那些数里存在，二分求边界，不用排序就是
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    vector<int> prim;
    vis[1]=true;
    for (int i=2;i<N-2;i++)
    {
        if(vis[i]==false)
        {
            prim.push_back(i);
            for(int j=i*2;j<N-2;j+=i)
                vis[j]=true;
        }
    }
    
    for(int i=1;i<=1e5;i++)
    {
        int x=i;
        for(int j=0;prim[j]<=x;j++)
        {
            if(x%prim[j]==0)
            {
                P st=m_p(prim[j],0);
                while(x%st.x==0){
                    x/=st.x;
                    st.y++;
                }
                cnt[i].push_back(st);
            }
        }
    }

    int t;cin>>t;
    while(t--)
    {

        int n,m;
        cin>>n>>m;
        {
        // vector<int> a(n+1);
        // for(int i=1;i<=n;i++){
        //     cin>>a[i];
        //     pre[i].clear();
        // }

        // for(int i=1;i<=n;i++)
        // {
        //     pre[i]=pre[i-1];
        //     for(auto &st:cnt[a[i]])
        //         pre[i][st.x]+=st.y;
        // }
        // while(m--)
        // {
        //     int l,r,p;
        //     cin>>l>>r>>p;
        //     map<int,int> now=pre[r];
        //     for(auto &st:pre[l-1])
        //         now[st.x]-=st.y;
        //     bool flag=true; 
        //     for(auto &st:cnt[p])
        //     {
        //         if(now[st.x]>=st.y) continue;
        //         else flag=false;
        //     }
        //     if(flag==false) cout<<"No"<<endl;
        //     else cout<<"Yes"<<endl;
        // }
        }

        for(int i=1;i<=int(1e5);i++) sum[i].clear();
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            for(auto &st:cnt[a[i]])
                for(int j=1;j<=st.y;j++) sum[st.x].push_back(i);
        }
        while(m--)
        {
            int l,r,p;
            cin>>l>>r>>p;
            bool flag=true;
            for(auto &st:cnt[p])
            {
                int pos=upper_bound(sum[st.x].begin(),sum[st.x].end(),r)-lower_bound(sum[st.x].begin(),sum[st.x].end(),l);
                if(pos<st.y){
                    flag=false;
                    break;
                }
            }
            if(flag) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}