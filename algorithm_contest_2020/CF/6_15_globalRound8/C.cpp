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

// bool plat[1005][1005]={false};
// // bool vis[1005][1005];
// int xx,yy;
// void push(queue<P> & que,const P& st){
//     que.push(st);
//     plat[st.x][st.y]=true;
//     // vis[st.x][st.y]=true;
// }
// int cont(queue<P> &que, P &st)
// {
//     int cnt=0;
//     bool t1,t2,t3,t4;
//     t2=t2=t3=t4=false;
//     if(plat[st.x][st.y+1]==false) {
//         cnt++;
//         push(que,m_p(st.x,st.y+1));
//         plat[st.x][st.y+1]=true;
//         t1=true;
//     }
//     if(plat[st.x][st.y-1]==false) {
//         cnt++;
//         push(que,m_p(st.x,st.y-1));
//         plat[st.x][st.y-1]=true;
//         yy=min(yy,st.y-1);
//         t2=true;
//     }
//     if(plat[st.x+1][st.y]==false) {
//         cnt++;
//         push(que,m_p(st.x+1,st.y));
//         plat[st.x+1][st.y]=true;
//         t3=true;
//     }
//     if(plat[st.x-1][st.y]==false) {
//         cnt++;
//         push(que,m_p(st.x-1,st.y));
//         plat[st.x-1][st.y]=true;
//         xx=min(xx,st.x-1);
//     }
//     if(cnt==2){

//     }
//     return cnt;
// }
// int main()
// {
//     IOS;
//     #ifdef _DEBUG
//     freopen("D:\\CODE\\code_contest\\out.txt","w",stdout);
//     freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);  
//     #endif
    
//     int k;
//     while(cin>>k)
//     {
//         queue<P> que;
//         LL ans=4;
//         P st(500,500);
//         xx=1005,yy=1005;
//         push(que,st);
//         push(que,m_p(st.x+1,st.y)); 
//         push(que,m_p(st.x,st.y+1));
//         push(que,m_p(st.x+1,st.y+1));
//         while(k--)
//         {
//             st=que.front();
//             que.pop();
//             ans+=cont(que,st);
//             // cout<<k<<":"<<ans<<endl;
//         }
//         cout<<ans<<endl;
//         for(int i=1;i<1005;i++)
//             for(int j=1;j<1005;j++)
//             {
//                 if(plat[i][j]==true){
//                     cout<<i-xx<<" "<<j-yy<<endl;
//                 }
//             }

//     }
//     return 0;
// }
//被这种简单粗暴的构造方式给秀到了
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);  
    #endif

    int k;cin>>k;
    cout<<3*k+4<<endl;
    cout<<0<<" "<<0<<endl<<0<<" "<<1<<endl;
    for(int i=1;i<=k;i++){
        cout<<i<<" "<<i-1<<endl;
        cout<<i<<" "<<i<<endl;
        cout<<i<<" "<<i+1<<endl;
    }
    cout<<k+1<<" "<<k<<endl;
    cout<<k+1<<" "<<k+1<<endl;    
    return 0;
}