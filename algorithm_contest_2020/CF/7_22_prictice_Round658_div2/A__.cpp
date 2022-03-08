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
pair<int,int> f[1005][1005];
//啊哈，做错了，
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
        memset(f,0,sizeof(f));
        int n,m;
        cin>>n>>m;
        vector<int> a(n+5),b(m+5);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=m;i++) cin>>b[i];
        //x为个数，y为上一位的位置(b中)
        pair<int, P > ans;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i]==b[j])
                {
                    f[i][j].x=f[i-1][j-1].x+1;
                    f[i][j].second=1;//来源于左上角
                }
                else if(f[i][j-1].x>f[i-1][j].x){
                    f[i][j].x=f[i][j-1].x;
                    f[i][j].y=2;//左
                }
                else{
                    f[i][j].x=f[i-1][j].x;
                    f[i][j].y=3;
                }
                if(ans.x<f[i][j].x) ans.first=f[i][j].x,ans.y=m_p(i,j);
            }

        }
        if(ans.x>0)
        {
            stack<int> sta;
            cout<<ans.x<<" ";
            
            for(int i=ans.y.x,j=ans.y.y;j;){
                sta.push(b[j]);
                while(f[i][j].y==3) i--;
                while(f[i][j].y==2) j--;
                if(f[i][j].y==1) i--,j--;
            }
            while(!sta.empty()){
                cout<<sta.top()<<' ';
                sta.pop();
            }cout<<endl;
        }
        else cout<<"NO"<<endl;
    }
    
    return 0;
}