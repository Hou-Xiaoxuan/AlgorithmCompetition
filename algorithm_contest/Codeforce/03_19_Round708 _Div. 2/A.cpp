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
typedef long double LD;
const int inf=0x3f3f3f3f;


int main()
{
    IOS;  

    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(101);
        for(int i=1;i<=n;i++){
            int x; cin>>x;
            a[x]++;
        }
        for(int i=0;i<=100;i++)
        {
            if(a[i]!=0){
                cout<<i<<' ';
                a[i]--;
            }
        }
        for(int i=0;i<=100;i++)
        {
            while(a[i]--) cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}
