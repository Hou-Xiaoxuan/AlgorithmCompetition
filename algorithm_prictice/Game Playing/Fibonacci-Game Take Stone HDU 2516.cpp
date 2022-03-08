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
const int N=1e6;
LL a[100];
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_prictice\\in.txt","r",stdin); 
    #endif
    
    a[1]=1;a[2]=2;
    int i;
    for(i=3;a[i-1]<(LL(1)<<31)+1;i++) a[i]=a[i-1]+a[i-2];
    
    int n;
    while(cin>>n and n!=0)
    {
        int cnt=lower_bound(a+1,a+90,n)-a;
        if(n==a[cnt]) cout<<"Second win"<<endl;
        else cout<<"First win"<<endl;
    }
    return 0;
}