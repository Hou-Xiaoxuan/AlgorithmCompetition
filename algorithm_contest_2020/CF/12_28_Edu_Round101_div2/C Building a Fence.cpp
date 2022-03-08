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

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> h(n+1),max_h(n+1),min_h(n+1);
        for(int i=1;i<=n;i++)
            cin>>h[i];
        max_h[1]=h[1]+k;
        min_h[1]=h[1]+1;
        bool flag=true;
        for(int i=2;i<n;i++)
        {
            if(max_h[i-1]<h[i]+1 or min_h[i-1]>h[i]+2*k-1){
                flag=false;
                break;
            }
            max_h[i]=min(max_h[i-1]+k-1,h[i]+2*k-1);
            min_h[i]=max(h[i]+1,min_h[i-1]-k+1);
        }
        if(!(h[n]+k>=min_h[n-1] and h[n]+1<=max_h[n-1])) flag=false;
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
