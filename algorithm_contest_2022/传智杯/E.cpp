/*
 * @Author: LinXuan
 * @Date: 2022-03-12 17:03:24
 * @Description: TLE了，没搞出来，等官方题解
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-15 13:14:21
 * @FilePath: /Algorithm/algorithm_contest_2022/传智杯/E.cpp
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

const int maxn=501000;
struct node{
    int v,next;
}e[2*maxn];
int fa[maxn][30],flag[maxn];
int head[2*maxn],d[maxn];
int n,m,s,tot;
void add(int x,int y){
    e[++tot].v=y;//增加一条边 
    e[tot].next=head[x];//边的另一端点是x 
    head[x]=tot;//以x为头的边表 
}
void dfs(int u,int w){
    d[u]=d[w]+1;
    fa[u][0]=w;
    for(int i=1;(1<<i)<=d[u];i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=head[u];i;i=e[i].next){
        int v=e[i].v;
        if(v!=w)dfs(v,u);
    }
    
}
int lca(int a,int b){//b是a的父亲节点 
    if(d[a]>d[b]) swap(a,b);//如果a的深度大于b则交换 
    for(int i=20;i>=0;i--)//树的深度小于20 
        if(d[a]<=d[b]-(1<<i))//如果b向上跳2的i次方深度还大于b 
            b=fa[b][i];//则跳 
    if(a==b) return a;//如果正好跳到a的位置，则返回a 
    for(int i=20;i>=0;i--){//ab同时向上跳 
        if(fa[a][i]!=fa[b][i]) //如果跳2的i次方不相等，则跳过去。 
            a=fa[a][i],b=fa[b][i];
    }
    return fa[a][0];//最后返回a的父亲； 
}

int main()
{
    #ifdef _DEBUG
    freopen("algorithm_contest_2022/传智杯/in.txt", "r", stdin);
    // freopen("algorithm_contest_2022/传智杯/out.txt", "w", stdout);
    #endif

    IOS
    cin>>n>>m;
    vector<LL> weight(n + 1);
    vector<pair<LL, int>> search_array(n + 1);
    for(int i=1; i<=n; i++){
        cin>>weight[i];
        search_array[i] = make_pair(weight[i], i);
    }
    for(int i=0; i<n-1; i++){
        int x, y;
        cin>>x>>y;
        add(x, y);
        add(y, x);
    }
    dfs(1, 0);
    vector<LL> vals(n + 1);
    vector<bool> vis(n + 1);
    function<void(int, LL)> dfs2 = [&](int node, LL pass_value){
        vals[node] = weight[node]^pass_value;
        pass_value = vals[node];
        vis[node] = true;
        for(int i=head[node];i;i=e[i].next){
            int v=e[i].v;
            if(vis[v] == false){
                dfs2(v, pass_value);
            }
        }
    };
    dfs2(1, 0);
    sort(search_array.begin() + 1, search_array.end());
    while(m--)
    {
        LL a, b, k;
        cin>>a>>b>>k;
        LL v = lca(a, b);
        LL tmp = vals[a]^vals[b]^weight[v]^k;
        auto ite = lower_bound(search_array.begin() + 1, search_array.end(), make_pair(tmp, -1));
        bool flag = false;
        while(ite != search_array.end() && ite->first == tmp){
                // 找到了
                // int f_a = lca(a, ite->second);
                // int f_b = lca(b, ite->second);
                // if(f_a == v and f_b == ite->second || f_a == ite->second and f_b == v){
                //     cout<<"Yes\n";
                //     flag = true;
                //     break;
                // } 
                int f_a = lca(a, ite->second);
                if(f_a == v){
                    int f_b = lca(b, ite->second);
                    if(f_b == ite->second){
                        flag = true;
                        break;
                    }
                } else if(f_a == ite->second){
                    int f_b = lca(b, ite->second);
                    if(f_b == v){
                        flag = true;
                        break;
                    }
                }
                ite++;
        }
        if (flag == false)
            cout<<"No\n";
        else
            cout<<"Yes\n";
        // cout<<endl;
    }
    return 0;
}
