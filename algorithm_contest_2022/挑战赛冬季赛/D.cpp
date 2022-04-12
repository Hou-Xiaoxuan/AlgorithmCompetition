/*
 * @Author: LinXuan
 * @Date: 2022-03-27 11:54:27
 * @Description: 
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-27 12:33:45
 * @FilePath: /Algorithm/algorithm_contest_2022/挑战赛冬季赛/D.cpp
 */
# ifndef _USE_MATH_DEFINES
# define _USE_MATH_DEFINES
# endif
# include<bits/stdc++.h>
# define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
# define  m_p make_pair
# define x first
# define y second 
using namespace std;
using LL=long long;
using ULL=unsigned long long;
using LD=long double;
using P=pair<int,int>;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;

struct Node
{
    int from;
    unordered_map<LL, int> ct;
    LL weight;
    LL ans;
    vector<pair<int, LL>> childs;
};


int main()
{
    IOS;
    # ifdef _DEBUG
    freopen("out.txt","w",stdout);
    freopen("in.txt","r",stdin);  
    # endif
    int n, m, c;
    cin>>n>>m>>c;
    vector<Node> tree(n + 1);
    vector<int> du(n+1, 0);
    for(int i=1; i<=n - 1; i++)
    {
        int from, to;
        LL weight;
        cin>>from>>to>>weight;
        tree[from].weight = weight;
        tree[from].childs.push_back({to, weight});
        tree[to].from = from; // 父亲
        du[from]++;
    }

    // 从底向上遍历
    queue<int> que;
    for(int i=1; i<=n; i++)
    {
        if(du[i] == 0){
            que.push(i); 
        }
    }
    while(que.empty() == false){
        int st = que.front();
        que.pop();
        // 先暴力 TODO: 优化每次重新计算的开销
        tree[st].ans = 0ll;
        for(auto child:tree[st].childs)
        {   
            // child<to, weight>
            for(auto item:tree[child.first].ct){
                tree[st].ct[item.first] += item.second;
            }
            // 释放资源
            tree[child.first].ct.clear();
            tree[st].ct[child.second]++;
        }
        for(auto item:tree[st].ct){
            tree[st].ans += (item.first*item.first*item.second*item.second);
        }
        du[tree[st].from]--;
        if(du[tree[st].from] == 0){
            que.push(tree[st].from);
        }
    }

    while(m--){
        int k; cin>>k;
        cout<<tree[k].ans<<endl;
    }
    return 0;
}
