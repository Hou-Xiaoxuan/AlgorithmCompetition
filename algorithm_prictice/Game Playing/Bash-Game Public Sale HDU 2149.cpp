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
// 这题有点坑啊，其实没有那么多选择的
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_prictice\\in.txt","r",stdin); 
    #endif
    
    int n,m;
    while(cin>>n>>m)
    {
        int tree=n%(m+1);
        if(tree==0) cout<<"none"<<endl;
        else
        {
            if(n<=m){
                for(int i=n;i<=m;i++) cout<<i<<(i==m?"":" ");
                cout<<endl;
            }
            else cout<<tree<<endl;
        }     
    }

    return 0;
}
