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
//这题也太坑了！！
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);  
    #endif

    int n,s;
    while(cin>>n>>s)
    {
        if(n*2>s){
            cout<<"NO"<<endl<<endl;
        }
        if(n*2<=s){
            cout<<"Yes"<<endl;
            for(int i=1;i<n;i++)
                cout<<2<<" ";
            cout<<s-2*(n-1)<<endl;
            cout<<1<<endl<<endl;
        }
    }
    return 0;
}