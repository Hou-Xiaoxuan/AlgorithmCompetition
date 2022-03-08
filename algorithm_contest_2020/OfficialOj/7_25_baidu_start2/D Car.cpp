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
//每天杯限号的车量均大于m'，求最大的m'

int ans=inf;
// int sum_of_zero=0;
vector<int> a[6];
int cnt[10];
void dfs(int st)
{
    // if(sum_of_zero>5) return;//剪枝
    if(st==10)
    {
        int tmp=0,sum=inf;
        // bool flag=true;
        // for(int i=1;i<=5;i++) if(a[i].size()!=2) flag=false;
       
        for(int i=1;i<=5;i++)
        {
            tmp=0;
            for(auto &j:a[i])
                tmp+=cnt[j];//这天限行的车数目
            sum=min(tmp,sum);//求出一周限行的最少数目
        }
        ans=max(ans,sum);
        return;
    }

    for(int i=1;i<=5;i++)
    {
        
        {
            a[i].push_back(st);
            dfs(st+1);
            a[i].pop_back();
        }
    }

}

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
        char s[7];
        int n;
        // cin>>n;
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        for(auto &i:a) i.clear();
        for(int i=1;i<=n;i++)
        {
            // cin>>s;
            scanf("%s",s);
            cnt[s[4]-'0']++;
        }
        int sum=0;
        for(int i=0;i<=9;i++){
            ans=min(cnt[i],ans);
            sum+=cnt[i];
        }
        dfs(0);
        // cout<<sum-ans<<endl;
        printf("%d\n",sum-ans);
    }
    return 0;
}