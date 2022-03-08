#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
//#include<bits/stdc++.h>
#include<string>
#include<iostream>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;

int perfectString(string &s, int k) 
{
    int cnt=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1') continue;
        if(s[i]=='0')
        {
            cnt++;
            int j;
            for(j=i+1;j<i+k and j<s.size();j++){
                if(s[j]=='0') continue;
                else break;
            }
            i=j-1;
        }
    }
    return cnt;
}
int main()
{
    IOS;
    #ifdef _DBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    string s="10101";

    cout<<perfectString(s,3)<<endl;
    return 0;
}