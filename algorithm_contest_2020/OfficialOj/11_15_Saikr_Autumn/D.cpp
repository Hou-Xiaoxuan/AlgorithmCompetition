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
// Wa了
int n;
double get_time(string &s)
{
    double ans=0;
    double v=1,time=0;
    for(auto i:s)
    {
        if(i=='.'){
            time=max(time,0.0);
            if(time==0) v=1.0;
            ans+=1.0/v;
            time-=0.5;
        }
        else if(i=='w'){
            time=max(time,0.0);
            if(time==0) v=1.0;
            ans+=2.0/v;
            time-=1;
        }
        else if(i=='>')
        {
            time=4.5;
            v=2.0;
            ans+=1.0/v;
        }
        else if(i=='s')
        {
            ans+=1;
            time-=1;
            time=max(time,0.0);
            if(time==0) v=1.0;
            ans+=1.0/v;
            time-=0.5;
        }
        else if(i=='m')
        {
            ans+=2;
            time-=2;
            time=max(time,0.0);
            if(time==0) v=1.0;
            ans+=1.0/v;
            time-=0.5;
        }

        time=max(time,0.0);
        if(time==0) v=1.0;
    }
    return ans;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif

    cin>>n;
    string s[5];
    for(int i=1;i<=4;i++) cin>>s[i];
    for(int i=1;i<=4;i++){
        cout.setf(ios::fixed);
        cout.precision(1);
        cout<<get_time(s[i])<<' ';
    }
    return 0;
}
