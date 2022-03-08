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
// 在年前年后的的判断出错*
const int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int countYear(pair<int,int> a,pair<int,int> b)
{
    if(a.first==b.first) return b.second-a.second;
    int ans=0;
    ans+=b.second;
    ans+=mon[a.first]-a.second;
    for(int i=a.first+1;i<=b.first-1;i++) ans+=mon[i];
    return ans;
}
string guessYear(vector<vector<int>> &inputQueries)
{
    
    string ans;
    for(auto &p:inputQueries)
    {
        pair<int,int> date1(p[0],p[1]),date2(p[2],p[3]),Run(2,29);
        int x=p[4];
        if(date1>Run and date2<Run){//本年二月后到明年二月前
            ans.push_back('?');
            continue;
            }
        if(date1<Run and date2>Run){//本年二月前到本年二月后
            int cnt=countYear(date1,date2);
            if(cnt==x) ans.push_back('P');
            else if(x==cnt+1) ans.push_back('R');
            continue;
        }
        if(date1>Run and date2>Run){//2月后到2月之后
            if(date1<date2){ ans.push_back('?');continue; }//到本年二月后
            int cnt=countYear(date1,make_pair(12,31))+countYear(make_pair(1,1),date2)+1;
            if(cnt==x) ans.push_back('?');//下一年不是闰年的话，不确定
            else if(cnt==x-1) ans.push_back('P');//下一年是闰年，一定是闰年
        }
        if(date1<Run and date2<Run){//2月前到2月前
            if(date1<date2) {ans.push_back('?');continue;}//到本年2月越前
            int cnt=countYear(date1,make_pair(12,31))+countYear(make_pair(1,1),date2)+1;
            if(cnt==x) ans.push_back('P');
            else if(cnt==x-1) ans.push_back('R');
        }
        // 日期中有2，29的话单独拿出来讨论
        if(date1==Run) ans.push_back('R');
        else if(date2==Run){
            if(date1<Run) ans.push_back('R');
            else ans.push_back('P');
        }
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
    
    vector<vector<int>> inputQueries={{3,1,5,31,91},{2,28,3,1,2},{12,31,1,1,1},{2,16,1,23,341}};
    cout<<guessYear(inputQueries)<<endl;
    return 0;
}