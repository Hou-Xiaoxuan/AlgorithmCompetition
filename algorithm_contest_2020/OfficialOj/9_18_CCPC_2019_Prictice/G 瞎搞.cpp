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
char ans1[(1<<1)+1][(1<<1)+1]={{'\0','C','C'},
                                {'\0','P','C'}};
char ans2[5][5];
char ans3[9][9];
char ans4[17][17];
char ans5[33][33];
char ans6[65][65];
char ans7[129][129];
char ans8[257][257];
char ans9[513][513];
char ans10[1025][1025];
// 嗨，瞎搞还没过，尴尬……
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    int n=4;
    for(int i=1;i<=(1<<n);i++)
        for(int j=1;j<=(1<<n);j++)
        {
            if(i>n/2 and j<=n/2) ans2[i][j]=ans1[(i+1)%(n/2)-1][(j+1)%(n/2)-1]=='C'?'P':'C';
            else ans2[i][j]=ans1[i][j];
        }
    n=3;
    for(int i=1;i<=(1<<n);i++)
        for(int j=1;j<=(1<<n);j++)
        {
            if(i>n/2 and j<=n/2) ans3[i][j]=ans2[(i+1)%(n/2)-1][(j+1)%(n/2)-1]=='C'?'P':'C';
            else ans3[i][j]=ans2[i][j];
        }
    n=4;
    for(int i=1;i<=(1<<n);i++)
        for(int j=1;j<=(1<<n);j++)
        {
            if(i>n/2 and j<=n/2) ans4[i][j]=ans3[(i+1)%(n/2)-1][(j+1)%(n/2)-1]=='C'?'P':'C';
            else ans4[i][j]=ans3[i][j];
        }
    n=5;
    for(int i=1;i<=(1<<n);i++)
        for(int j=1;j<=(1<<n);j++)
        {
            if(i>n/2 and j<=n/2) ans5[i][j]=ans4[(i+1)%(n/2)-1][(j+1)%(n/2)-1]=='C'?'P':'C';
            else ans5[i][j]=ans4[i][j];
        }
    n=6;
    for(int i=1;i<=(1<<n);i++)
        for(int j=1;j<=(1<<n);j++)
        {
            if(i>n/2 and j<=n/2) ans6[i][j]=ans5[(i+1)%(n/2)-1][(j+1)%(n/2)-1]=='C'?'P':'C';
            else ans6[i][j]=ans5[i][j];
        }
    n=7;
    for(int i=1;i<=(1<<n);i++)
        for(int j=1;j<=(1<<n);j++)
        {
            if(i>n/2 and j<=n/2) ans7[i][j]=ans6[(i+1)%(n/2)-1][(j+1)%(n/2)-1]=='C'?'P':'C';
            else ans7[i][j]=ans6[i][j];
        }
    n=8;
    for(int i=1;i<=(1<<n);i++)
        for(int j=1;j<=(1<<n);j++)
        {
            if(i>n/2 and j<=n/2) ans8[i][j]=ans7[(i+1)%(n/2)-1][(j+1)%(n/2)-1]=='C'?'P':'C';
            else ans8[i][j]=ans7[i][j];
        }
    n=9;
    for(int i=1;i<=(1<<n);i++)
        for(int j=1;j<=(1<<n);j++)
        {
            if(i>n/2 and j<=n/2) ans9[i][j]=ans8[(i+1)%(n/2)-1][(j+1)%(n/2)-1]=='C'?'P':'C';
            else ans9[i][j]=ans8[i][j];
        }
    n=10;
    for(int i=1;i<=(1<<n);i++)
        for(int j=1;j<=(1<<n);j++)
        {
            if(i>n/2 and j<=n/2) ans10[i][j]=ans9[(i+1)%(n/2)-1][(j+1)%(n/2)-1]=='C'?'P':'C';
            else ans10[i][j]=ans9[i][j];
        }



    
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        if(n==1)
            for(int i=1;i<=2;i++)
            {
                for(int j=1;j<=n;j++)
                    cout<<ans1[i][j];
                cout<<endl;
            }
     else if(n==2)
        for(int i=1;i<=(1<<n);i++)
        {
            for(int j=1;j<=(1<<n);j++)
                cout<<ans2[i][j];
            cout<<endl;
        }
    else if(n==3)
        for(int i=1;i<=(1<<n);i++)
        {
            for(int j=1;j<=(1<<n);j++)
                cout<<ans3[i][j];
            cout<<endl;
        }
    else if(n==4)
        for(int i=1;i<=(1<<n);i++)
        {
            for(int j=1;j<=(1<<n);j++)
                cout<<ans4[i][j];
            cout<<endl;
        }
    else if(n==5)
        for(int i=1;i<=(1<<n);i++)
        {
            for(int j=1;j<=(1<<n);j++)
                cout<<ans5[i][j];
            cout<<endl;
        }
    else if(n==6)
        for(int i=1;i<=(1<<n);i++)
        {
            for(int j=1;j<=(1<<n);j++)
                cout<<ans6[i][j];
            cout<<endl;
        }
    else if(n==7)
        for(int i=1;i<=(1<<n);i++)
        {
            for(int j=1;j<=(1<<n);j++)
                cout<<ans7[i][j];
            cout<<endl;
        }
    else if(n==8)
        for(int i=1;i<=(1<<n);i++)
        {
            for(int j=1;j<=(1<<n);j++)
                cout<<ans8[i][j];
            cout<<endl;
        }
    else if(n==9)
        for(int i=1;i<=(1<<n);i++)
        {
            for(int j=1;j<=(1<<n);j++)
                cout<<ans9[i][j];
            cout<<endl;
        }
    else if(n==10)
        for(int i=1;i<=(1<<n);i++)
        {
            for(int j=1;j<=(1<<n);j++)
                cout<<ans10[i][j];
            cout<<endl;
        }
    }
    return 0;
}