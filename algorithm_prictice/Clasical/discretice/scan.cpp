//https://www.luogu.com.cn/problem/P2032
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_k make_pair
#define   P  pair<int,int>
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;


void solve1()
{
    //topycal momotonous queue
    int n,k;cin>>n>>k;
    vector<int> a(n+1);
    deque<int> que;
    for(int i=k+1;i<=n;i++)
    {
        cin>>a[i];
        while(!que.empty() and que.front()<=i-k) que.pop_front();
        while(!que.empty() and a[que.back()]<=a[i]) que.pop_back();
        que.push_back(i);
        if(i>k-1)   cout<<a[que.front()]<<endl;
    }

}

struct node{
    int value;
    int order;
    node(int a=0,int b=0):value(a),order(b){};
    bool operator<(const node a)const{
        return value<a.value;
    }
};
void solve2()
{
    //sonthing interesting
    priority_queue<node,vector<node> > que;
    int n,k;cin>>n>>k;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        que.push(node(a[i],i));
        if(i>=k)
        {
            while(que.top().order<=i-k) que.pop();
            cout<<que.top().value<<endl;
        }
    }
}
int main()
{
    IOS
    //freopen("D:\\CODE\\code_prictice\\in.txt","w",stdout);
    //freopen("D:\\CODE\\code_prictice\\in.txt","r",stdin);
    solve2();
    return 0;
}