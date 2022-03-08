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

struct node
{
    int a,b,c,d;
    node(int aa,int bb,int cc,int dd):a(aa),b(bb),c(cc),d(dd){};
};
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    map<int,int > ma;
    
    for(int n=1;n<=50;n++)
    {
        for(int a=0;a<=n;a++)
            for(int b=0;b<=n;b++)
                for(int c=0;c<=n;c++)
                    for(int d=0;d<=n;d++)
                        if(a+b+c+d==n){
                            ma[a+b*5+c*10+d*50]++;
                        }
        int cnt1=0,cnt2=0;
        for(auto i:ma)
        {
            if(i.second==1){
                cnt1++;
            }
            else cnt2++;
        }
        cout<<n<<": "<<cnt1+cnt2<<" "<<cnt1<<" "<<cnt2<<endl;
        cout<<"------------------\n";
    }
    return 0;
}
