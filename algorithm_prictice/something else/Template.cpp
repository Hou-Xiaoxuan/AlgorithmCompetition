// 计蒜客 欧拉筛模板题
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e6;
bool vis[N+5];
int prim[N],tot=0;
void init_prime()
{

// 欧拉筛
    for(int i=2;i<=N;i++)
    {
        if(vis[i]==false) prim[++tot]=i;
        for(int j=1;j<=tot and i*prim[j]<=N;j++)
        {
            vis[i*prim[j]]=true;
            if(i%prim[j]==0) break;
        }
    }
}
