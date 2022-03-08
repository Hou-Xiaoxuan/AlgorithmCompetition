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

// struct node
// {
//     node(int a,int b,int c):t(a),x(b),
//     int ord;//人物编号1~n
//     int t;//时间
//     int x;//地点
// };
vector<int> state[105][15];//地点,时间
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int t;cin>>t;
    while(t--)
    {
        memset(state,0,sizeof(state));
        // vector<int> a(1);//储存第i个数据的编号
        int n;cin>>n;
        vector<bool> vis(n+5);//感染日期
        // for(auto &i:vis) i=-1;
        for(int i=1;i<=n;i++)
        {
            int m,tt,pp;
            cin>>m;
            for(int j=1;j<=m;j++)
            {
                cin>>tt>>pp;
                // a.push_back(node(tt,pp,n));
                state[tt][pp].push_back(i);
            }
        }
        
        vis[1]=true;//第一个已经感染
        /*开始遍历*/
        for(int it=1;it<=100;it++)//时间
            for(int ip=1;ip<=10;ip++)//地点
            {
                if(state[it][ip].size()<=1) continue;
                bool flag=false;
                for(auto &i:state[it][ip])
                    if(vis[i]==true) 
                        flag=true;//这一批次感染
                if(flag==true)
                {
                    for(auto &i:state[it][ip])
                        vis[i]=true;
                }
            }

        int first=-1;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==true)
            {
                if(first==-1){
                    cout<<i;
                    first=0;
                }
                else cout<<" "<<i;
            }
        }
        cout<<endl;
    }
    return 0;
}