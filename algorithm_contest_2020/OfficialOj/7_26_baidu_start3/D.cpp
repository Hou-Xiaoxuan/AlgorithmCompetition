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
/*
*右车道到车正常行驶就是最优情况
*左车道车正常行驶，有最大的答案：tmp+3
*左车道优化到又扯到，答案有答案：tmp+2
*只有最后一辆车能决定是否存在优化。
*/
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int test;cin>>test;
    while(test--)
    {
        int n;cin>>n;
        int a=0,b=0;
        set<int> vis;
        int x,y;
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y;
            if(x==1){
                vis.insert(y);
                b=max(b,y);
            }
            else if(x==2)
                a=max(a,y);
        }
        int ans=b+1;
        if(vis.count(a+1)==0) 
            ans=max(ans,a+2);
        else ans=max(ans,a+3);
        
        cout<<ans<<endl;
        

    }
    return 0;
}