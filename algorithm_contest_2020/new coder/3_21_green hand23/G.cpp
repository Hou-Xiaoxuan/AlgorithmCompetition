#include<bits/stdc++.h>
using namespace std;
//真的卡常数
//唯一一道做出来的
typedef long long LL;
int main()
{
    int n;cin>>n;
    vector< vector<int> > edg(n+1);
    vector<int> du(n+1),a(n+1);
    int x,y;
    for(int i=1;i<=n-1;i++){
        cin>>x>>y;
        edg[x].push_back(y);
        edg[y].push_back(x);
        du[x]++;du[y]++;
    }
    queue<int> que;
    vector<long long> cnt;
    vector<bool> vis(n+1);
    for(int i=1;i<=n;i++) if(du[i]==1){
        que.push(i);
        vis[i]=true;
    }
    while(!que.empty())
    {
        int s=que.front();
        vis[s]=true;
        que.pop();
        if(du[s]!=1) continue;
        cnt.push_back(LL(a[s]+1)*LL(n-a[s]-1));
        for(int i=0;i<edg[s].size();i++)
            if(vis[edg[s][i]]==false){
                a[edg[s][i]]+=(a[s]+1);
                du[edg[s][i]]--;
                if(du[edg[s][i]]==1)
                    que.push(edg[s][i]);
            }
    }
    long long ans=0;
    sort(cnt.begin(),cnt.end());
    for(int i=0;i<n;i++)
        ans+=LL(cnt[i])*LL((n-i-1));
    cout<<ans<<endl;
    return 0;
}