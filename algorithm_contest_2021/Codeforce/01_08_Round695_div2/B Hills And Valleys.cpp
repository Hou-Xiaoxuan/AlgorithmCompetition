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
// 改变一个值只可能-3，-2，-1
// 改变有个值也可以不变……我构造不出来，反正存在~
// A了
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #elif _LINUX
    freopen("/media/linxuan/储存/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("/media/linxuan/储存/CODE/algorithm_contest/in.txt","r",stdin);
    #endif
    
    int t;cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        vector<int> a(n+1);
        
        for(int i=1;i<=n;i++) cin>>a[i];
        bool flag[4]={false};
        int ans=0;

        // for(int i=2;i<n;i++)
        // {
        //     if(a[i]>a[i-1] and a[i]+a[i+1]) ans++;
        //     if(a[i]<a[i-1] and a[i]<a[i+1]) ans++;
        //     if(i+2<=n and a[i]<a[i-1] and a[i]<a[i+1] and a[i+2]<a[i+1]) flag[2]=true;
        //     if(i+2<=n and a[i]>a[i-1] and a[i]>a[i+1] and a[i+2]>a[i+1]) flag[2]=true;
        //     if(i+3<=n and a[i]<a[i-1] and a[i]<a[i+1] and a[i+2]<a[i+1] and a[i+2]<a[i+3]) flag[3]=true;
        //     if(i+3<=n and a[i]>a[i-1] and a[i]>a[i+1] and a[i+2]>a[i+1] and a[i+2]>a[i+3]) flag[3]=true;
        // }
        // if(flag[3]==true) ans-=3;
        // else if(flag[2]==true) ans-=2;
        // else if(flag[1]==true) ans--;
        // cout<<max(ans,0)<<endl;

        // vector<bool> statu(n+1);
        // for(int i=2;i<n;i++)
        // {
        //     if(a[i]>a[i-1] and a[i]+a[i+1]) statu[i]=true;
        //     else if(a[i]<a[i-1] and a[i]<a[i+1]) statu[i]=true;
        // }
        // int ans=0,cnt=0,tmp=0;
        // for(int i=2;i<n;i++)
        // {
        //     if(statu[i]==true){
        //         ans++;tmp++;
        //     }
        //     else{
        //         cnt=max(cnt,tmp);
        //         tmp=0;
        //     }
        // }
        // cnt=max(cnt,tmp);
        // cout<<ans-min(cnt,3)<<endl;
    
        auto check = [](int x,int n,vector<int>&a)->int{
            if(x==1 or x==n)
                return 0;
            if(a[x]>a[x+1] and a[x]> a[x-1]) return 1;
            else if(a[x]<a[x+1] and a[x]<a[x-1]) return 1;
            return 0;
        };
        for(int i=2;i<n;i++)
        {
            ans+=check(i,n,a);
            int num[2];
            num[0]=check(i,n,a)+check(i-1,n,a)+check(i+1,n,a);
            int save=a[i];

            a[i]=min(a[i-1],a[i+1]);
            num[1]=check(i,n,a)+check(i-1,n,a)+check(i+1,n,a);
            a[i]=max(a[i-1],a[i+1]);
            num[2]=check(i,n,a)+check(i-1,n,a)+check(i+1,n,a);
            flag[ max(num[0]-min(num[1],num[2]),0)]=true;//num[0]与num[1] or num[2]的差值几位最大将少数木，当然，不能小于0

            a[i]=save;//恢复数据
        }
        if(flag[3]==true) ans-=3;
        else if(flag[2]==true) ans-=2;
        else if(flag[1]==true) ans-=1;
        cout<<ans<<endl;
    }
    return 0;
}
