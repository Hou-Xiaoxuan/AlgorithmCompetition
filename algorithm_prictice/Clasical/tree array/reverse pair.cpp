//https://www.luogu.com.cn/problem/P1908
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
//逆序对：这题去年我竟然做过（但是现在已经不会了emmm，用树状数组再来一边
//相同的数据问题未解决
const int N=1e6;
int c[N];
void change(int p,int n,int x){
    while(p<=n){
        c[p]+=x;
        p+=(-p)&p;
    }
}
LL ask(int p){
    LL sum=0;
    while(p>0){
       sum+=c[p];
       p-= (-p)&p;
    }
    return sum;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_prictice\\in.txt","r",stdin);  
    #endif
    int n;cin>>n;
    memset(c,0,sizeof(int)*(n+5));
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b.begin()+1,b.end());
    int m=unique(b.begin()+1,b.end())-b.begin()-1;
    map<int,int> mp;
    for(int i=1;i<=m;i++){
        mp[b[i]]=i;
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        int t=mp[a[i]];
        change(t,n,1);
        ans+=i-ask(t);
        #ifdef _DEBUG
        cout<<i<<" "<<t<<" "<<i-ask(t)<<""<<endl;
        #endif
    }
    cout<<ans<<endl;
    return 0;
}