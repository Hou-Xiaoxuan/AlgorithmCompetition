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

bool judge(string &s1, string &s2)
{
    if(s1.size()!=s2.size()) return false;
    int len=s1.size();
    for(int j=0;j<len;j++)
    {
        bool flag=true;
        for(int i=0;i<len;i++)
            if(s1[(i+j)%len]!=s2[i]){
                flag=false;
                break;
            }
        if(flag==true) return true;
    }
    return false;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    string s1="abcd";
    string s2="cdab";
    cout<<(int)judge(s1,s2)<<endl;   
    return 0;
}