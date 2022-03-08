#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;

LL fb[60]={0};
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);  
    #endif
    fb[1]=1;fb[2]=0;
    for(int i=3;i<=45;i++)
        fb[i]=fb[i-1]+fb[i-2];
    string sa,sb;   cin>>sa>>sb;
    int n;  cin>>n;
    LL ca[300]={0},cb[300]={0};

    // for(int i=0;i<sa.length();i++){
    //     ca[int(tolower(sa[i]))]++;
    // }
    // for(int i=0;i<sb.length();i++) {
    //    cb[int(tolower(sb[i]))]++;
    // }

    // for(int i=1;i<=200;i++)
    //     if(ca[i]*fb[n]+ cb[i]*fb[n+1]!=0)
    //         cout<<char(i)<<": "<<ca[i]*fb[n]+ cb[i]*fb[n+1]<<endl;

    for(int i=0;i<int(sa.length());i++){
        ca[int(sa[i])]++;
    }
    for(int i=0;i<int(sb.length());i++) {
       cb[int(sb[i])]++;
    }
    for(int i=1;i<=200;i++)
        if((ca[i]*fb[n]+ cb[i]*fb[n+1])!=0)
            cout<<char(i)<<": "<<ca[i]*fb[n]+ cb[i]*fb[n+1]<<endl;
    return 0;
}