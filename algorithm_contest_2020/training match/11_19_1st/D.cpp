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

// 后缀自动机什么玩意！！！
// 我爱假题解
// 确实复杂度怎么算也过不了啊……
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #else
    freopen("curse.in","r",stdin);
    #endif

    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case "<<i<<":"<<endl;
        string s1,s2;
        cin>>s1>>s2;
        int q;
        cin>>q;
        string st="";
        size_t l,r;
        while(q--)
        {
            cin>>l>>r;
            l--,r--;
            size_t index,pre;
            index=pre=l;
            LL ans=0;
            while(index<=r)//每次从index开始搜索
            {
                st="";
                st+=s1[index];
                pre=index;
                while(s2.find(st)!=string::npos and index<=r)
                    index++,st+=s1[index];
                if(index!=pre) ans+=(index-pre+1)*(index-pre)/2;//计数
                else index++;
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}
