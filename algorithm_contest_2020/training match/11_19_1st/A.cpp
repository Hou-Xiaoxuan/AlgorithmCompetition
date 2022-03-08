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

void dfs(LL a,vector<int>&array)
{
    if(a==1) return;
    LL k=1,cnt=0;
    while(k<a){
        k<<=1;
        cnt++;
    }
    array.push_back(cnt);
    dfs(k-a,array);
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif

    LL a,b;
    while(cin>>a>>b)
    {
        vector<int> array;
        dfs(a,array);
        sort(array.begin(),array.end(),greater<int>());
        // for(auto i:array) cout<<i<<" ";
        // cout<<endl;
        if(array.size()==0)
        {
            for(int i=0;i<b;i++) cout<<0;
            cout<<endl;
            continue;
        }
        for(int i=1;i<=b;i++)
        {
            cout<<0;
            if(!array.empty() and i==array.back()){
                cout<<1;
                array.pop_back();
            }
        }
        cout<<endl;
    }
    return 0;
}
