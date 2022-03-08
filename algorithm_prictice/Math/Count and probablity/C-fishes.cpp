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
//Ìâ½â £ºÌ°ÐÄ+BFS
int m,n,r,k;
struct nod{
    int x;
    int y;
    int v;
    nod(int a,int b,int c):x(a),y(b),v(c){};
    bool operator<(const nod &s)const{
        return v<s.v;
    }
};
double get(P s)
{
    double a=min(s.x+r-1,n)-max(s.x,r)+1;
    double b=min(s.y+r-1,m)-max(s.y,r)+1;
    return double(a*b);
}
int dx[]={0,0,0,1,-1};
int dy[]={0,1,-1,0,0};
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_prictice\\in.txt","r",stdin);  
    #endif
    while(cin>>n>>m>>r>>k)
    {
        set<P > vis;
        priority_queue<nod> que;
        P s=m_p((n+1)>>1,(m+1)>>1);
        vis.insert(s);
        nod t(s.x,s.y,get(s));
        que.push(t);
        LL ans=0;
        while(k--)
        {
            t=que.top();
            que.pop();
            ans+=t.v;
            // #ifdef _DEBUG
            // cout<<"("<<t.x<<","<<t.y<<")=";
            // cout<<t.v<<endl;
            // #endif
            for(int i=1;i<=4;i++)
            {
                P s=m_p(t.x+dx[i],t.y+dy[i]);
                if(vis.count(s)==0 and s.x>=1 and s.y>=1 and s.x<=n and s.y<=m){
                    que.push(nod(s.x,s.y,get(s)));
                    vis.insert(s);
                }
            }
        }
        cout.precision(10);
        cout<<double(ans)/double(LL(n-r+1)*(m-r+1))<<endl;
    }
    return 0;
}