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
int Fivecharacterpalindrome(string &s) {
    // write your code here

    long long cnt=0;
    for(int i=2;i<s.size()-2;i++)
    {
        if(s[i-2]==s[i+2] and s[i-1]==s[i+1] and s[i-2]!=s[i-1] and s[i-1]!=s[i] and s[i]!=s[i-2]) cnt++;
    }

    return cnt;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    string s="abcbabcccb";
    cout<<Fivecharacterpalindrome(s)<<endl;
   
    return 0;
}