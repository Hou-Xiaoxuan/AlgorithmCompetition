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
// 思维题：直接选择x,y的中位数进行平移就可以了
// 假设最终交点为 x,则线段 [l, r] 移动到 x 的代价为
//[|l−x|+|r−x|−(r−l)]/2，只有中间与x有关。明显，x去中间值的时候最短
struct node{
    LL x1,y1,x2,y2;
    node(LL a=0,LL b=0,LL c=0, LL d=0):x1(a),y1(b),x2(c),y2(d) {};
}dot[int(1e5+5)];
int dx[2*int(1e5+5)],dy[2*int(1e5+5)];
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
        int n;cin>>n;
        int x1,x2,y1,y2;
        for(int i=1;i<=n;i++)
        {
            cin>>x1>>y1>>x2>>y2;
            dot[i]=node(x1,y1,x2,y2);
            dx[(i<<1)-1]=x1;
            dx[i<<1]=x2;
            dy[(i<<1)-1]=y1;
            dy[i<<1]=y2;
        }
        sort(dx+1,dx+n*2+1);
        sort(dy+1,dy+n*2+1);
        LL x=dx[n],y=dy[n];
        LL ans=0;
        for(int i=1;i<=n;i++){
            ans+=(abs(x-dot[i].x1)+abs(x-dot[i].x2)-dot[i].x2+dot[i].x1)/2;
            ans+=(abs(y-dot[i].y1)+abs(y-dot[i].y2)-dot[i].y2+dot[i].y1)/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}