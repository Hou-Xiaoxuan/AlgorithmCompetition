#include<bits/stdc++.h>
using namespace std;
#define  m_k make_pair
#define   P  pair<int,int>
#define  V vector
typedef long long LL;
typedef unsigned long long ULL;
char s[2005][2005];
int cnt[2005][2005];
int main()
{
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_contest\\in.txt","r",stdin); 
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    int t;cin>>t;
    int n,m;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                cin>>s[i][j];
                cnt[i][j]=1;            
            }
        //int ans=0;//最后一刻，这里，初始化为1即可
        int ans=1;
        for(int i=1;i<=n;i++)
        { 
            for(int j=1;j<=m;j++)
            {
                if(s[i][j]==s[i][j-1] and s[i][j]==s[i-1][j] and s[i][j]==s[i-1][j-1]){
                    cnt[i][j]=min(min(cnt[i-1][j],cnt[i][j-1]),cnt[i-1][j-1])+1;
                    ans=max(ans,cnt[i][j]);
                }
            }
        }
        /*for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                    cout<<cnt[i][j]<<" ";
                cout<<endl;
            }*/
        cout<<ans<<endl;
    }
    return 0;
}