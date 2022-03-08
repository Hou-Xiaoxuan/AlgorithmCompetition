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
// 01 trie模板题

const int N=4e6;
int next_pos[N+5][2];
int pos=0;
void insert(int val)
{
    int p=0;
    for(int i=30;i>=0;i--)
    {
        int x=(val>>i)&1;
        if(next_pos[p][x]==0) next_pos[p][x]=++pos;
        p=next_pos[p][x];
    }
}
int find_max_xor(int val)
{
    int p=0;
    int ans=0;
    for(int i=30;i>=0;i--)
    {
        int x = (val>>i)&1;
        if(next_pos[p][x^1]){
            ans = ans | (1<<i);
            p=next_pos[p][x^1];
        }
        else{
            p=next_pos[p][x];
        }
    }
    return ans;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin); 
    #endif
    int n;
    while(cin>>n)
    {
        memset(next_pos,0,sizeof(next_pos));
        pos=0;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            insert(a[i]);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            ans=max(ans,find_max_xor(a[i]));
        cout<<ans<<endl;
    return 0;
    }
}
