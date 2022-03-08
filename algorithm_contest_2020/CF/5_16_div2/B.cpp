#define _USE_MATH_DEFINES
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
int a[300000+5];
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);  
    #endif
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        int l=1,r=1;
        int cnt=0;
        while(r<=n){
            if(r-l+1>=a[r]){
                cnt++;
                //cout<<l<<"-"<<r<<" "<<a[r]<<endl;
                l=++r;
            }
            else r++;
        }
        cout<<cnt<<endl;


    }

    return 0;
}