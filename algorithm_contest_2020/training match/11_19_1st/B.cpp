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

    vector<int> a(6);
    for(int i=1;i<=5;i++)
        cin>>a[i];
    int ans=0;
    for(int i=1;i<=5;i++)
        for(int j=i+1;j<=5;j++)
            for(int k=j+1;k<=5;k++)
            {
                if(a[i]+a[j]>a[k] and a[i]+a[k]>a[j] and a[j]+a[k]>a[i]) ans++;
            }
    cout<<ans<<endl;
    return 0;
}
