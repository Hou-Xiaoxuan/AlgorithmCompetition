#include<bits/stdc++.h>
using namespace std;
//Œ‘≤€£¨æπ»ªπ˝¡À£°
typedef pair<int,int> P;
#define  mp make_pair
bool cmp(P a,P b){
    return a.first<b.first;
}
int main()
{
    int n;  cin>>n;
    vector< vector<P > >a(n+1);
    vector<bool> vis(n+1);
    vector<int> du(n+1);
    vector<P > ans;
    int u,v;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        a[u].push_back(mp(v,i));
        a[v].push_back(mp(u,i));
        du[u]++;du[v]++;
    }
    int st,tmp=-1;
    for(int i=1;i<=n;i++)
        if(tmp<du[i]){
            tmp=du[i];
            st=i;
    }
    queue<int> que;
    que.push(st); vis[st]=true;
    int cnt=0;
    while(!que.empty())
    {
        int s=que.front(); que.pop();
        for(int i=0;i<a[s].size();i++)
            if(vis[a[s][i].first]==false){
                ans.push_back(mp(a[s][i].second,cnt++));
                vis[a[s][i].first]=true;
                que.push(a[s][i].first);
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].second<<endl;
    return 0;
}