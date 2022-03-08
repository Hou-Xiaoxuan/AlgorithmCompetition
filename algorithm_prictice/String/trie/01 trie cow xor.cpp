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
// 异或和建树
const int N=4e6;
int trie[N+5][2],value[N+5];
int pos=0;
void insert(int val,int index)
{
    int p=0;
    for(int i=20;i>=0;i--)
    {
        int x=((val>>i)&1);
        if(trie[p][x]==0) trie[p][x]=++pos;
        p=trie[p][x];
    }
    value[p]=index;
}
int find_max_xor(int val)
{
    int p=0;
    int ans=0;
    for(int i=20;i>=0;i--)
    {
        int x=((val>>i)&1);
        if(trie[p][x^1]){
            ans+=(1<<i);
            p=trie[p][x^1];
        }
        else{
            p=trie[p][x];
        }
    }
    // cout<<ans<<" "<<p<<" "<<value[p]<<" "<<endl;
    return value[p];
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
        vector<int> a(n+1);
        cin>>a[1];
        insert(a[1],1);
        int ans=a[1],u=1,v=1;
        for(int i=2;i<=n;i++)
        {
            cin>>a[i];
            a[i]^=a[i-1];
            insert(a[i],i);
            int tmp = find_max_xor(a[i]);
            if(ans<(a[i]^a[tmp])){
                ans=a[i]^a[tmp];
                u=tmp+1;
                v=i;
            }
        }
        cout<<ans<<" "<<u<<" "<<v<<endl;
    }
    return 0;
}
