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
int prim[int(1e4)+5];
bool vis[int(1e4)+5];
vector<int> vec[10005];
int cnt=0;
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    for(int i=2;i<10000;i++)
    {
        if(vis[i]==false)
        {
            prim[++cnt]=i;
            for(int j=i*2;j<=10000;j+=i)
                vis[j]=true;
        }
    }

    int n;cin>>n;
    vector<int> a(n+1);
    int cnt1=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int val=a[i];
        if(val==1) cnt1++;
        for(int j=1;j<=cnt and prim[j]<=val;j++)
        {
            if(val%prim[j]==0)
            {
                int tmp=a[i];
                while(val%prim[j]==0){
                    val/=prim[j];
                    tmp/=prim[j];
                }
                vec[j].push_back(tmp);
            }
        }
        if(a[i]==val and val!=1) vec[0].push_back(val);
    }
    int ans=0;
    for(int i=0;i<=cnt;i++)
    {
        if(vec[i].empty()) continue;
        sort(vec[i].begin(),vec[i].end());
        int sum=0;
        int cnt_tmp_1=0;
        while(cnt_tmp_1<vec[i].size() and vec[i][cnt_tmp_1]==1) cnt_tmp_1++;
        int cnt=0;
        if(cnt_tmp_1!=vec[i].size()) cnt=1;
        for(int j=cnt_tmp_1+1;j<vec[i].size();i++)
        {
            if(vec[i][j-1]==vec[i][j]) cnt++;
            else{
                sum=max(sum,cnt);
                cnt=1;
            }
        }
        sum=max(sum,cnt);
        ans=max(sum+cnt_tmp_1,ans);
    }
    ans+=cnt1;
    cout<<ans<<endl;
    return 0;
}