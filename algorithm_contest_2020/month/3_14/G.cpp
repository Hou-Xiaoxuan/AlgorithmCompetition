#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
char a[N][N];
char ans[N][N];
int dx[]={1,1,1,0,0,-1,-1,-1};
int dy[]={1,0,-1,1,-1,1,0,-1};
int get(int x,int y){
    int cnt=0;
    for(int i=0;i<8;i++)
        if(a[x+dx[i]][y+dy[i]]=='*')
            cnt++;
    return cnt;
}
int main()
{
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>a[i][j];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(a[i][j]=='?')
                    ans[i][j]=get(i,j)+'0';
                else
                    ans[i][j]='*';                  
            }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                cout<<ans[i][j];
            cout<<endl;
        }
    }
    return 0;
}