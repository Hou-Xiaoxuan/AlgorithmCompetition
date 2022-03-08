/*
 * @Author: LinXuan
 * @Date: 2021-08-11 09:25:04
 * @Description: 
 * @LastEditors: LinXuan
 * @LastEditTime: 2021-08-11 10:13:40
 * @FilePath: \c++\B.cpp
 */
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define x first
#define y second 
using namespace std;
using LL=long long;
using ULL=unsigned long long;
using LD=long double;
using P=pair<int,int>;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;

vector<vector<char>> graph;
int n, m, k;
int get_dis(P st, P target) 
{
    graph[target.x][target.y] = '.';
    vector<vector<int>> dis(n+1, vector<int>(m+1, inf));
    vector<vector<bool>> vis(n+1, vector<bool>(m+1, false));
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    dis[st.x][st.y] = 0;
    // bfs
    queue<P> que;
    que.push(st);
    vis[st.x][st.y] = true;
    while(!que.empty())
    {
        st = que.front();
        que.pop();
        if(st == target){
            break;
        }
        for(int i=0; i<4; i++)
        {
            P tmp = P(st.x + dx[i], st.y + dy[i]);
            if(tmp.x>=1 and tmp.x<=n and tmp.y>=1 and tmp.y<=m and graph[tmp.x][tmp.y] == '.')
            {
                if(vis[tmp.x][tmp.y] == false)
                {
                    vis[tmp.x][tmp.y] = true;
                    dis[tmp.x][tmp.y] = dis[st.x][st.y] + 1;
                    que.push(tmp);
                }
            }
        }
    }
    return dis[target.x][target.y];
}

int main()
{
    IOS;
    #ifdef _DEBUG
    // freopen("D:\\CODE\\c++\\out.txt","w",stdout);
    freopen("D:\\CODE\\c++\\in.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) 
    {
        cin>>n>>m>>k;
        P st;
        cin>>st.x>>st.y; // 当前所处的位置
        graph = vector<vector<char>>(n+1, vector<char>(m+1, inf));
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++){
                cin>>graph[i][j];
                // cout<<graph[i][j]<<endl; // debug
            }
        vector<P> bom(k+1);
        for(int i=1;i<=k;i++){
            cin>>bom[i].x>>bom[i].y;
            graph[bom[i].x][bom[i].y] = '$';
            // cout<<bom[i].x<<" "<<bom[i].y<<endl; // debug
        }
        bool flag = true;
        int ans = 0;
        for(int i=1;i<=k;i++)
        {
            int dis = get_dis(st, bom[i]);
            cout<<"debug: "<<dis<<endl;
            if(dis == inf){
                flag = false;
                break;
            }
            ans += dis - 1;
            st = bom[i];
            
        }
        if(flag == true) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
