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
    freopen("D:\\CODE\\code_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_prictice\\in.txt","r",stdin);  
    #endif
    
    int t;cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a<b) swap(a,b);
        int cnt=0;
        while(a<=c)
        {
            cnt++;
            b+=a;
            swap(a,b);
        }
        cout<<cnt<<endl;
    }

    return 0;
}