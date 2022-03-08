#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
// #include<bits/stdc++.h>
#include <iostream>
#include <functional>
#include<vector>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<iso646.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
const int inf=0x3f3f3f3f;

// 需要求任意两点的最短电梯距离和最长滑雪距离，但是Floyed的话n=1000复杂度肯定不行……所以利用SPFA的玄学复杂度求n次，最终复杂度为O(k*n*n)，k一般不超过2
// 终于不是MLE了，RE了……
// 这bug是找不出来了……建议重做吧
// ????A了????为什么要判断除数是不是inf啊？
// 原因分析：当ans=0时，不能到达的点距离为inf也会更新ans，然后在求路径过程中就会出错
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #elif _LINUX
    freopen("/media/linxuan/储存/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("/media/linxuan/储存/CODE/algorithm_contest/out.txt","r",stdin);
    #endif

    int n,m,k;
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        vector<vector<P>> edg_lift(n+1),edg_ski(n+1);
        for(int i=1;i<=m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            edg_ski[v].push_back(P(u,w));//为了之后好操作，反向存边
        }
        for(int i=1;i<=k;i++){
            int u,v,w;
            cin>>u>>v>>w;
            edg_lift[u].push_back(P(v,w));
        }
        // 默认不存在环
        vector<int> dis_lift(n+1),dis_ski(n+1);
        vector<int> front_lift(n+1),front_ski(n+1);//记录路径，每个节点的上一个点
        vector<bool> vis_lift(n+1),vis_ski(n+1);//标记这个值是否已经在队列里面
        function<void(int)> SPFA_lift=[&](int st)->void
        {
            //求电梯距离的最小值;
            fill(dis_lift.begin(),dis_lift.end(),inf);
            fill(front_lift.begin(),front_lift.end(),-1);
            fill(vis_lift.begin(),vis_lift.end(),0);
            dis_lift[st]=0;
            vis_lift[st]=true;
            queue<int> que;
            que.push(st);
            while(!que.empty())
            {
                st=que.front();
                vis_lift[st]=false;
                que.pop();
                for(auto &e:edg_lift[st])
                    if(dis_lift[st]+e.y<dis_lift[e.x])
                    {
                        front_lift[e.x]=st;
                        dis_lift[e.x]=dis_lift[st]+e.y;
                        if(vis_lift[e.x]==false){
                            que.push(e.x);
                            vis_lift[e.x]=true;
                        }
                    }
            }
        };
        function<void(int)> SPFA_ski=[&](int st)->void
        {
            //求滑雪距离的最大值;
            fill(dis_ski.begin(),dis_ski.end(),0);
            fill(front_ski.begin(),front_ski.end(),-1);
            fill(vis_ski.begin(),vis_ski.end(),0);
            queue<int> que;
            que.push(st);
            vis_ski[st]=true;
            while(!que.empty())
            {
                st=que.front();
                vis_ski[st]=false;
                que.pop();
                for(auto &e:edg_ski[st])
                    if(dis_ski[st]+e.y>dis_ski[e.x])
                    {
                        front_ski[e.x]=st;
                        dis_ski[e.x]=dis_ski[st]+e.y;
                        if(vis_ski[e.x]==false){
                            que.push(e.x);
                            vis_ski[e.x]=true;
                        }

                    }
            }
        };

        double ans=0;
        vector<int> path;
        for(int i=1;i<=n;i++)//从i出发
        {
            if(edg_lift[i].empty() or edg_ski[i].empty()) continue;//剪枝
            SPFA_lift(i);
            SPFA_ski(i);
            for(int j=1;j<=n;j++)//到达j点
            {
                if(i==j or dis_lift[j]==inf) continue;
                if(1.0*dis_ski[j]/dis_lift[j]>ans)//更新答案
                {
                    ans=1.0*dis_ski[j]/dis_lift[j];
                    // 储存路径
                    int st=j;
                    vector<int>().swap(path);
                    while(st!=i){
                        path.push_back(st);
                        st=front_lift[st];
                    }
                    path.push_back(i);
                    reverse(path.begin(),path.end());
                    path.pop_back();//去掉多余的一个中间节点
                    st=j;
                    while(st!=i){
                        path.push_back(st);
                        st=front_ski[st];
                    }
                    path.push_back(i);
                }
            }
        }
        for(auto i:path) cout<<i<<" ";
        cout<<endl<<fixed<<setprecision(3)<<ans<<endl;
        // MLE了，清理掉vector占用的内存试一下
        vector<int>().swap(dis_lift);
        vector<int>().swap(dis_ski);
        vector<int>().swap(front_lift);
        vector<int>().swap(front_lift);
        vector<vector<P>>().swap(edg_lift);
        vector<vector<P>>().swap(edg_ski);
        vector<bool>().swap(vis_lift);
        vector<bool>().swap(vis_ski);
    }
    return 0;
}
