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
//每天杯限号的车量均大于m'，求最大的m'

//醉了，不管了，反正这样过了
//为什么都是dfs，我的就过不了啊
int aa[15],al[15]; 
int cnt,ans,n;
void dfs(int st,int a,int b,int c,int d,int e)
{
    if(st==cnt+1)
    {
        int tmp=0;
        tmp=max(n-a,tmp);
        tmp=max(n-b,tmp);
        tmp=max(n-c,tmp);
        tmp=max(n-d,tmp);
        tmp=max(n-e,tmp);
        ans=min(tmp,ans);
        return;
    }
    dfs(st+1,a+al[st],b,c,d,e);
    dfs(st+1,a,b+al[st],c,d,e);
    dfs(st+1,a,b,c+al[st],d,e);
    dfs(st+1,a,b,c,d+al[st],e);
    dfs(st+1,a,b,c,d,e+al[st]);
}
int main()
{
    // IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int x;
        memset(aa,0,sizeof(aa));
        for(int i=1;i<=n;++i){           
            scanf("%d",&x);           
            aa[x%10]++;
        }
        cnt=0; ans=inf;
        for(int i=0;i<=9;++i) if(aa[i]!=0) al[++cnt]=aa[i];
        dfs(1,0,0,0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}