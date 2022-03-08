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

// 画图找规律，找到PN点的规律
// 能保持自己两个坐标都是奇数的赢得胜利
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_prictice\\in.txt","r",stdin); 
    #endif
    
    int n,m;
    while(1)
    {
        cin>>n>>m;
        if(n==0 and m==0) break;

        if(m&1==1 and n&1==1) cout<<"What a pity!"<<endl;
        else cout<<"Wonderful!"<<endl;
    }


    return 0;
}