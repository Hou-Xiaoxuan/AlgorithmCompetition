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
bool cmp(const P&a,const P&b){
    if(a.first==b.first)
        return a.second<b.second;
    else return a.first>b.first;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int n,m;
    cin>>n>>m;
    int x;
    vector<P >a(n+1);
    for(int i=1;i<=n;i++){
        cin>>x;
        a[i].second=x;
    }
    for(int i=1;i<=m;i++){
        cin>>x;
        a[x].first=i;
    }
    sort(a.begin()+1,a.end(),cmp);
    for(int i=1;i<=n;i++) {
        // cout<<a[i].second<<(i==n?"":" ");
        cout<<a[i].second<<" ";
    }
    return 0;
}