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
// 补题：
int st[100005][20];
int st2[100005][20];
int search_min(int x,int y)
{
    int k=log(double(y-x+1))/log(2.0);
    return min(st[x][k],st[y-(1<<k)+1][k]);
}
int search_max(int x,int y)
{
    int k=log(double(y-x+1))/log(2.0);
    return max(st2[x][k],st2[y-(1<<k)+1][k]);
}
int Intervalxor(vector<int> &num, vector<vector<int>> &ask)
{   
    // initiate:
    for(int i=1;i<=num.size();i++) st[i][0]=st2[i][0]=num[i-1];
    for(int j=1;1<<j<=num.size();j++)
        for(int i=1;i+(1<<j)-1<=num.size();i++){
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            st2[i][j]=max(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
        }

    long long sum=0;
    int l1,l2,r1,r2;
    for(int i=0;i<ask.size();i++)
    {
        
        l1=ask[i][0];
        r1=ask[i][1];
        l2=ask[i][2];
        r2=ask[i][3];
        cout<<search_max(l1,r1)+search_min(l2,r2)<<"debug"<<endl;
        sum^=(search_max(l1,r1)+search_min(l2,r2));
    }
    return sum;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    vector<int> a={1,2,3,4,5};
    vector<vector<int> > b={{1,2,3,4},{1,2,4,5}};
    cout<<Intervalxor(a,b)<<endl;
    return 0;
}