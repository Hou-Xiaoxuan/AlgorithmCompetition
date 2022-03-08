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
// 复习默写kmp
const int N=1e6+5;
int kmp[N];
int strs[N],strp[int(1e4+5)];
// 处理的时较短的那个字符串啊！！
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin); 
    #endif
    
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>strs[i];
        for(int i=1;i<=m;i++) cin>>strp[i];
        // get_kmp
        int j=0;
        kmp[1]=0;
        for(int i=2;i<=m;i++)
        {
            while(j>0 and strp[j+1]!=strp[i]) j=kmp[j];
            if(strp[j+1]==strp[i]) j++;
            kmp[i]=j;
        }
        j=0;
        for(int i=1;i<=n;i++)
        {
            while(j>0 and strp[j+1]!=strs[i]) j=kmp[j];
            if(strs[i]==strp[j+1]) j++;
            if(j==m){
                cout<<i-m+1<<endl;
                break;
            }
        }
        if(j!=m) cout<<-1<<endl;
    }
    return 0;
}
