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
    
    int t; cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int> a(2*n+1);
        queue<int> single,even;
        for(int i=1;i<=n*2;i++)
        {
            cin>>a[i];
            // if(a[i]==1) continue;
            if(a[i]%2==1) single.push(i);
            else even.push(i);
        }
        for(int i=1;i<=n-1;i++)
        {
            if(single.size()>=2){
                cout<<single.front()<<" ";
                single.pop();
                cout<<single.front()<<endl;
                single.pop();
                
            }
            else if(even.size()>=2){
                cout<<even.front()<<" ";
                even.pop();
                cout<<even.front()<<endl;
                even.pop();
            }
        }
        



    }
    return 0;
}