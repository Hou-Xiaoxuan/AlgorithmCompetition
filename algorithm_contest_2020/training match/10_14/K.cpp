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
char ans[10][20]={"    WA    ","    TLE   ","    AC    ","    AC*   "};
void setcenter(string&s)
{
    int len=s.size();
    if(len==2){
        s="    "+s+"    ";
    }
    else{
        s="    "+s+"   ";
    }
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    int t;cin>>t;
    while(t--)
    {
        string s1,s2,s3;
        int a,b,c;
        cin>>a>>s1>>b>>s2;
        if(s2=="Running"){
            cin>>c;
            while(c--) s3.push_back('X');
            while(s3.size()<10) s3.push_back(' ');
        }
        else
        {
            if(s2=="FB") s3="AC*";
            else s3=s2;
            setcenter(s3);
        }
        
        cout<<setw(3)<<right<<a<<'|'<<setw(16)<<left<<s1<<'|'<<setw(4)<<left<<b<<"|["<<s3<<']'<<endl;
    
    }
    return 0;
};