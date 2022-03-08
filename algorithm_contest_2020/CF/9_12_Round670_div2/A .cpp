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
        int n;cin>>n;
        // min
        // int a=-1,b=-1;
        // for(int i=0;i<=100;i++){
        //    if(cnt[i]!=2) a=i;
        //    if(a!=-1) break;
        // }
        // for(int i=0;i<=100;i++){
        //     if(cnt[i]==0) b=i;
        //     else if(cnt[i]==1 and a!=i) b=i;
        //     if(b!=-1) break;
        // }
        vector<bool> a(101);
        vector<bool> b(101);
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            if(a[x]==0) a[x]=1;
            else b[x]=1;
        }
        int ans=0;
        for(int i=0;i<=100;i++)
            if(a[i]==0){
                ans+=i;
            break;}
        for(int i=0;i<=100;i++)
            if(b[i]==0){
                ans+=i;
            break;}
        cout<<ans<<endl;

    }
    return 0;
}