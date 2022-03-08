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
int f[1005][1005];
bool jungle(int n,int m)
{
   int t=0;
		while(m>0) {
			t=n%m;
			n=m;
			m=t;//当=0说明两个数之间存在倍数关系
		}
		if(n==1)return true;
		return false;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    f[1][1]=1;
    for(int i=1;i<=1000;i++)
        f[1][i]=f[i][1]=i;
    for(int i=2;i<=1000;i++)
        for(int j=2;j<=1000;j++){
            f[i][j]=max(f[i][j-1],f[i-1][j])+(jungle(j,i)==true?1:0);
        }
    int t; cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if(x<y) swap(x,y);
        cout<<f[x][y]<<endl;
    }
    return 0;
}