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

string str;
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif

    int t;
    cin>>t;
    while(t--)
    {

        cin>>str;
        int n=str.size();

        int ans=0;
        for(int i=1;i<n;i++)
        {
            /*判断能不能作为奇数轴右边或者偶数轴的右边*/
            bool vis[26]={false};
            bool flag=false;//是否冲突
            if(i-1>=0 and str[i]==str[i-1])
                flag=true;
            if(i-2>=0 and str[i]==str[i-2])
                flag=true;
            if(flag==true)
            {
                for(int j=max(0,i-2);j<=min(n-1,i+2);j++)
                    vis[str[j]-'a']=true;
                ans++;
                for(int j=0;j<26;j++)
                    if(vis[j]==false){
                        str[i]='a'+j;
                        break;
                    }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
