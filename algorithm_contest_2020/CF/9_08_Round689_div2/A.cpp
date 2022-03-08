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
        vector<int>a(n+5);
        int cnt[2]={0};
        for(int i=1;i<=n;i++){
            cin>>a[i];
            cnt[a[i]]++;
        }
        if(cnt[0]>=cnt[1])
        {
            cout<<n/2<<endl;
            for(int i=1;i<=n/2;i++) cout<<"0 ";
            cout<<endl;
        }
        else
        {
            int m=n/2+(n/2)%2;
            cout<<m<<endl;
            for(int i=1;i<=m;i++) cout<<"1 ";
            cout<<endl;
        }
        
        // 虽然AC了，但是做的太复杂了
        // if(n==2){
        //     if(a[1]==a[2] and a[2]==1) cout<<2<<endl<<1<<" "<<1<<endl;
        //     else cout<<1<<endl<<0<<endl;
        //     continue;
        // }
       
        // int m=n/2;
        // if(m%2==0)
        // {
        //     cout<<m<<endl;
        //     if(cnt[1]>=cnt[0])
        //         for(int i=1;i<=m;i++) cout<<1<<" ";
        //     else 
        //         for(int i=1;i<=m;i++) cout<<0<<" ";
        //     cout<<endl;
        // }
        // else
        // {
            
        //     if(cnt[1]!=cnt[0])
        //     {
        //         m++;
        //         cout<<m<<endl;
        //         if(cnt[1]>=cnt[0])
        //             for(int i=1;i<=m;i++) cout<<1<<" ";
        //         else 
        //             for(int i=1;i<=m;i++) cout<<0<<" ";
        //         cout<<endl;
        //     }
        //     else
        //     {
        //         bool flag=false;
        //         cout<<m<<endl;
        //         int cnt=0;
        //         vector<int> ans;
        //         for(int i=1;i<=n;i++)
        //         {
        //             if(a[i]==1 and cnt<m-1){ans.push_back(1);cnt++;}
        //             if(flag==false and a[i]==0 and cnt%2==0) {ans.push_back(0); flag=true;}
        //         }
        //         if(flag==false){
        //             cout<<0<<' ';
        //             for(int i=1;i<m;i++) cout<<1<<' ';
        //             cout<<endl;
        //         }
        //         else{
        //             for(auto &i:ans) cout<<i<<' ';
        //             cout<<endl;
        //         }
        //     }
        // }
        
        
    }
    return 0;
}