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
// 反尼姆博弈的变形
bool stringGame(string &s)
{
    vector<int>a(27);
    for(auto&i:s) a[i-'a']++;
    int nim=0;
    int cnt=0;
    int sum=0;
    for(int i=0;i<26;i++){
        nim^=a[i];
        if(a[i]!=0) sum++;
        if(a[i]==1) cnt++;
    }

    if(sum==cnt and (sum&1)==0) return true;
    else if(sum!=cnt and nim!=0) return true;
    return false;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    string s="acacbcbc";
    cout<<(stringGame(s)==true?"TRUE":"FALSE")<<endl;
   
    return 0;
}