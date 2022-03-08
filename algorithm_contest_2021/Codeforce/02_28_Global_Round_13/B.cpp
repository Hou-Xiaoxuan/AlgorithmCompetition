#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define x first
#define y second 
using namespace std;
using LL=long long;
using ULL=unsigned long long;
using LD=long double;
using P=pair<int,int>;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #endif
    
    int t; cin>>t;
    while(t--)
    {
        int n,u,v;
        cin>>n>>u>>v;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        const int m=1e6+1;
        bool flag=false;
        // 是否联通
        for(int i=2;i<=n;i++)
        {
            if(abs(a[i-1]-a[i]<=1)) continue;
            else{
                flag=true;
                break;
            }
        }
        if(flag==true){//如果不需要移动
            cout<<0<<endl;
            continue;
        }
        map<int,int> ans;
        for(int i=1;i<=n;i++)
        {
            if(i==1)//在上边界
            {
                if(a[i+1]==a[i])//正下方
                {
                    ans[u+v]=1;
                    if(a[i]>=2 or a[i]<=m-1) ans[u+v]=1;
                }
                else if(a[i+1]==a[i]-1)//左下方
                {
                    ans[u]=1;
                    if(a[i]<=m-1) ans[v]=1;
                }
                else if(a[i+1]=a[i]+1)//右下方
                {
                    ans[u]=1;
                    if(a[i]>=1) ans[v]=1;
                }
            }
            else if(i==n)//在下边界
            {
                if(a[i-1]==a[i])
                {
                    ans[u+v]=1;
                    if(a[i]>=2 or a[i]<=m-1) ans[u+v]=1;
                }
                else if(a[i-1]==a[i]-1)
                {
                    ans[u]=1;
                    if(a[i]<=m-1) ans[v]=1;
                }
                else if(a[i-1]=a[i]+1)
                {
                    ans[u]=1;
                    if(a[i]>=1) ans[v]=1;
                }
            }
            else
            {
                if(a[i-1]==a[i+1])
                {
                    if(a[i-1]==a[i]-1){
                        ans[u]=1;
                        if(a[i]<=m-1) ans[v]=1;
                    }
                    else if(a[i-1]=a[i]+1){
                        ans[u]=1;
                        if(a[i]>=1) ans[v]=1;
                    }
                    else
                    {
                        ans[u+v]=1;
                        if(a[i]>=2 or a[i]<=m-1) ans[2*v]=1;
                    } 
                }
                else
                {
                    ans[u]=1;
                    ans[v]=1;
                }       
            }
            
        }
        cout<<min_element(ans.begin(),ans.end())->first<<endl;
    }
    return 0;
}
