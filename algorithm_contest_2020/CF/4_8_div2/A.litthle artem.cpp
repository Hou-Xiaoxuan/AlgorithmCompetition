#include<bits/stdc++.h>
using namespace std;
#define  m_k make_pair
#define   P  pair<int,int>
#define  V vector
typedef long long LL;
typedef unsigned long long ULL;
char mp[105][105];
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;
        if(n*m&1)//ji
        {
            for(int i=1;i<=n;i++)
            {
                if(i&1)
                    for(int j=1;j<=m;j++)
                        mp[i][j]= j&1?'B':'W';
                else
                    for(int j=1;j<=m;j++)
                        mp[i][j]= j&1?'W':'B';
            }
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                if(i&1)
                    for(int j=1;j<=m;j++)
                        mp[i][j]= j&1?'B':'W';
                else
                    for(int j=1;j<=m;j++)
                        mp[i][j]= j&1?'W':'B';
            }
            mp[1][2]='B';
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                cout<<mp[i][j];
            cout<<endl;
        }
    }

    return 0;
}