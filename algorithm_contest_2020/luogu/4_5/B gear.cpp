#include<bits/stdc++.h>
using namespace std;
#define  m_k make_pair
#define   P  pair<int,int>
#define  V vector
typedef long long LL;
typedef unsigned long long ULL;
int n,m,k;
const int N=1e6+5;
int a[N],cnt[N];
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
void get(vector<int>&b)
{
    int tmp=b[0];
    for(int i=1;i<int(b.size());i++)
        tmp=gcd(tmp,b[i]);
                //cout<<b[0]<<" "<<b[1]<<":"<<tmp<<endl;
    if(tmp<=m) cnt[tmp]++;
}
void dfs(int i,int t,int k,int n,vector<int>&b)
{
    if(t==k)
    {     
        get(b);
        return;
    }
    if(i>n) return;
   
    dfs(i+1,t,k,n,b);
    b.push_back(a[i]);
    dfs(i+1,t+1,k,n,b);
    b.pop_back();
    return;
}
int main()
{
    
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    memset(cnt,0,sizeof(cnt));
    if(k==1)
    {
        for(int i=1;i<=n;i++){
            if(a[i]<=m)
                cnt[a[i]]++;
        }
    }
    else
    {
        vector<int> b;
        dfs(1,0,k,n,b);
    }
    for(int i=1;i<=m;i++)
        cout<<cnt[i]<<' ';
    cout<<endl;
    return 0;
}