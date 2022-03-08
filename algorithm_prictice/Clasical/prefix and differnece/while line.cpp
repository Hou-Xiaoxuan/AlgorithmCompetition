//https://codeforces.ml/contest/1200/problem/D
//��άǰ׺�ͣ����ǣ�1��1������i��i���ĺ�;
#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int mp[N][N]={0};
char s[N][N];
void add(int x1,int y1,int x2,int y2)
{
    mp[x1][y1]++;
    mp[x1][y2+1]--;
    mp[x2+1][y1]--;
    mp[x2+1][y2+1]++;
}
int main()
{
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>(s[i]+1);
    for(int i=1;i<=n;i++)
    {   
        int l=0,r;
        for(int j=1;j<=n;j++)
            if(s[i][j]=='B'){
                if(l==0) l=j;
                r=j;
        }
        if(l==0) add(1,1,n,n);
        else if(r-l+1<=k) add(max(1,i-k+1),max(1,r-k+1),i,l);//�����Χ�ڵ���������������i��
    }
    for(int j=1;j<=n;j++)
    {
        int u=0,d;
        for(int i=1;i<=n;i++)
            if(s[i][j]=='B'){
                if(u==0) u=i;
                d=i;
            }
        if(u==0) add(1,1,n,n);
        else if(d-u+1<=k) add(max(1,d-k+1),max(1,j-k+1),u,j);//�����Χ�ڵ�������������j��
    }
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {   
            mp[i][j]+= mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1];
            //cout<<mp[i][j];
            ans=max(ans,mp[i][j]);
        }
        //cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}