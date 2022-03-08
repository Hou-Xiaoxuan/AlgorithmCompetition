#include<bits/stdc++.h>
using namespace std;
//题解说，我们要倒着来！
/*虽然不清楚原理，但是矛盾数据：（正着来不行的数据）1 5 4 2 3-》1 5 2 4 2
1

5 4

1 4

4 2

5 3

3 2
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin>>T;
    const int N=200;
    while(T--)
    {
        int n,m; cin>>n>>m;
        vector<bool> vis(N+1);
        vector<int> ans(N+1),in(N+1),vec[N+1];
        int u,v;
        for(int i=1;i<=m;i++){
            cin>>u>>v;
            vec[v].push_back(u);
            in[u]++;
        }
        queue<int> que;//实际上我自己模拟了一个优先队列
        for(int i=n;i>=1;i--)
            if(in[i]==0){
                 que.push(i);
                 vis[i]=true;
                 break;
            }
        int cnt=n;
        while(!que.empty())
        {
            int s=que.front(); que.pop();
            ans[s]=cnt--;
            for(int j=0;j<vec[s].size();j++)
                in[vec[s][j]]--;
            for(int i=n;i>=1;i--)
                if(vis[i]==false and in[i]==0){
                    que.push(i);
                    vis[i]=true;
                    break;
                }
        }
        if(cnt!=0)
            cout<<-1<<endl;
        else{
            for(int i=1;i<=n;i++)
                cout<<ans[i]<<' ';
            cout<<endl;
        }
    }

    return 0;
}
