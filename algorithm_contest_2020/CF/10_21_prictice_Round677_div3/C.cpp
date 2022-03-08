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
        int n; cin>>n;
        vector<LL> a(n+5),ans(n+5),sum(n+5);
        LL maxn=-1;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]>maxn){
                maxn=a[i];
                cnt=0;
                ans[++cnt]=i;
            }
            else if(a[i]==maxn) ans[++cnt]=i;
        }
        if(cnt==1) {
            cout<<ans[1]<<endl;
            continue;
        }
        else
        {
            // 猜测1：只要可能就行，不是必须，所以就默认其他与不能动
            // woc,直接过了
            maxn=-1;
            int index=-1;
            LL tmp=0;
            ans[cnt+1]=n+1;
            for(int i=1;i<=cnt;i++)
            {
                sum[i]=ans[i]-ans[i-1]+ans[i+1]-ans[i]-2;
                if(sum[i]>=maxn){
                    maxn=sum[i];
                    tmp++;
                    index=ans[i];
                }
            }
            if(maxn!=0 and index!=-1) cout<<index<<endl;
            else cout<<-1<<endl;
        }
        
    

    }
    return 0;
}