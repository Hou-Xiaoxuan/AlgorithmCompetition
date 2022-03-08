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

// BFS试一下，估计输入不好搞
int sum[1005][1005];

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int n,m;
    while(cin>>n>>m)
    {
        cin.ignore();
        memset(sum,0x3f,sizeof(sum));
        vector<string> str(2*m+2);
        for(int i=0;i<2*m+1;i++)
        {
            getline(cin,str[i]);
        }
        P st;
        queue<P> que;
        // 找到入口
        for(int i=1;i<2*n+1;i+=2)
        {
            if(str[0][i]==' '){
                que.push(m_p(1,i));
                sum[1][i]=1;
            }
            if(str[2*m][i]==' '){
                que.push(m_p(2*m-1,i));
                sum[2*m-1][i]=1;
            }
        }
        for(int j=1;j<2*m;j+=2)
        {
            if(str[j][0]==' '){
                que.push(m_p(j,1));
                sum[j][1]=1;
            }
            if(str[j][2*n]==' '){
                que.push(m_p(j,2*n-1));
                sum[j][2*n-1]=1;
            }
        }
        // while(!que.empty())
        // {
        //     cout<<que.front().first<<" "<<que.front().second<<endl;
        //     que.pop();
        // }
        // cout<<endl;
        while(!que.empty())
        {
            st=que.front();
            que.pop();
            if(st.x==75 and sum[st.x][st.y]==199){
                bool flag=false;
                if(flag==false) flag=true;
            }
            // 上：
            if(st.x-2>=1 and str[st.x-1][st.y]==' ' and str[st.x-2][st.y]==' ')
                if(sum[st.x][st.y]+1<sum[st.x-2][st.y]){
                    sum[st.x-2][st.y]=sum[st.x][st.y]+1;
                    que.push(m_p(st.x-2,st.y));
                }
            if(st.x+2<=2*m-1 and str[st.x+1][st.y]==' ' and str[st.x+2][st.y]==' ')
                if(sum[st.x][st.y]+1<sum[st.x+2][st.y]){
                    sum[st.x+2][st.y]=sum[st.x][st.y]+1;
                    que.push(m_p(st.x+2,st.y));
                }
            // 左
            if(st.y-2>=1 and str[st.x][st.y-1]==' ' and str[st.x][st.y-2]==' ')
                if(sum[st.x][st.y]+1<sum[st.x][st.y-2]){
                    sum[st.x][st.y-2]=sum[st.x][st.y]+1;
                    que.push(m_p(st.x,st.y-2));
                }
            if(st.y+2<=2*n-1 and str[st.x][st.y+1]==' ' and str[st.x][st.y+2]==' ')
                if(sum[st.x][st.y]+1<sum[st.x][st.y+2]){
                    sum[st.x][st.y+2]=sum[st.x][st.y]+1;
                    que.push(m_p(st.x,st.y+2));
                }
        }
        int ans=-1;
        for(int i=1;i<2*m;i+=2)
            for(int j=1;j<2*n;j+=2)
            {
                if(sum[i][j]!=sum[0][0]){
                    // if(sum[i][j]>ans){cout<<i<<" "<<j<<endl;}
                    ans=max(ans,sum[i][j]);
                }
            }
        cout<<ans<<endl;

        for(int i=0;i<=2*m;i++)
            for(int j=0;j<=2*n;j++)
            {
                if(i&1 && j&1){
                    if(sum[i][j]==sum[0][0]) cout<<"INF";
                    else cout<<setw(3)<<sum[i][j];
                }
                else cout<<setw(3)<<str[i][j];
                if(j==2*n) cout<<endl;
            }
    }
    return 0;
}
