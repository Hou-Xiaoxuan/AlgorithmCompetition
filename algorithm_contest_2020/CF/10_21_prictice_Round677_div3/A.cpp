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
int a[9][5];
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int t; cin>>t;
    for(int i=1;i<=9;i++)
        for(int j=1;j<=4;j++)
        {
            if(j==1) a[i][j]=a[i-1][4]+j;
            else a[i][j]=a[i][j-1]+j;
        }
    while(t--)
    {
        int n;cin>>n;
        int x=n%10;
        int y=0;
        while(n){
            y++;
            n/=10;
        }
        cout<<a[x][y]<<endl;

    }
    return 0;
}