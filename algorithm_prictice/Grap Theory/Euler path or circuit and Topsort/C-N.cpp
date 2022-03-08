#include<bits/stdc++.h>
using namespace std;
//ÖÐÎÄ
int main()
{
    int n,m; 
    while(cin>>n>>m)
    {
        vector<int> vec[10005];
        vector<int> in(n+1),reward(n+1);
        queue<int> que;
        int u,v;
        for(int i=1;i<=m;i++){
            cin>>u>>v;
            in[u]++;
            vec[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
            if(in[i]==0){
                que.push(i);
                reward[i]=888;
            }
        int cnt=n;
        while(!que.empty())
        {
            int s=que.front();
            cnt--,que.pop();
            for(int i=0;i<vec[s].size();i++){
                in[vec[s][i]]--;
                reward[vec[s][i]]=max(reward[vec[s][i]],reward[s]+1);
                if(in[vec[s][i]]==0)
                    que.push(vec[s][i]);
            }
        }
        if(cnt) cout<<-1<<endl;
        else {
            int ans=0;
            for(int i=1;i<=n;i++) ans+=reward[i];
            cout<<ans<<endl;       
        }
    }
    return 0;
}