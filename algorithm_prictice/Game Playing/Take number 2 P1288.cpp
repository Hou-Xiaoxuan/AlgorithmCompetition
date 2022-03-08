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
// 思维 博弈论

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_prictice\\in.txt","r",stdin); 
    #endif
    
    int n;
    while(cin>>n)
    {
        vector<int>a(n+1);
        int l=-1,r=-1;
        for(int i=1;i<=n;i++)
        {   
            cin>>a[i];
            if(a[i]==0)
            {
                if(l!=-1) r=i;
                else l=i;
            }
        }
        if(r==-1) r=l;
        if((l-1)&1==1 or r!=-1 and (n-r)&1==1 ) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}