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
// 思维题
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
        vector<int> a(n+1);
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]==i) flag++;
        }
        if(flag==n){
            cout<<0<<endl;//有序
            continue;
        }
        // 从前往后
        for(int i=1;i<=n;i++){
            if(a[i]==i) flag--;
            else break;
        }
        for(int i=n;i;i--){
            if(a[i]==i) flag--;
            else break;
        }
        if(flag==0) cout<<1<<endl;//去除两边仍然有吻合的
        else cout<<2<<endl;
        
        
    }

    return 0;
}