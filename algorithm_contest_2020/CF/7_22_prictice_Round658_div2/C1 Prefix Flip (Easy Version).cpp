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
        queue<int> ans;
        string a,b;
        cin>>a>>b;
        if(a[0]!=b[0]) ans.push(1);
        for(int i=1;i<a.size();i++)
        {
            if(a[i]!=b[i])
            {
                ans.push(i+1);ans.push(1);ans.push(i+1);
            }
        }
        cout<<ans.size()<<" ";
        while(!ans.empty()){
            cout<<ans.front()<<" ";
            ans.pop();
        }cout<<endl;
    }
    return 0;
}