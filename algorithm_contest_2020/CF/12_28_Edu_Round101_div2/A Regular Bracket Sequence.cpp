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


int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int cnt[3]={0},ct=0,condition=0;//1左2右
        bool flag=false;
        if(s.size()%2)
        {
            cout<<"No"<<endl;
            continue;
        }
        for(auto ch:s)
        {
            if(ch=='?') cnt[ct]++;
            else if(ch=='(')
            {
                if(condition==0) condition=1;
                ct++;
            }
            else if(ch==')')
            {
                if(condition==0) condition=2;
                ct++;
            }
        }
        if(condition==1)
        {
            // if(cnt[0]%2==0 and cnt[1]%2==0 and cnt[2]%2==0)
                flag=true;
        }
        else if(condition==2)
        {
            if(cnt[0]>0 and cnt[2]>0)
                flag=true;
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}
