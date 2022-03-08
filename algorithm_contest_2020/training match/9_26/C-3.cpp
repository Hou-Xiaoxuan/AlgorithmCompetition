#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<node,node>
#define k first
#define b second 
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
};
struct node//分数a/b
{
    node(LL aa=0,LL bb=1):a(aa),b(bb){div();};
    LL a;
    LL b;
    void div(){
        LL d=gcd(a,b);
        a/=d;
        b/=d;
    }
    bool operator<(const node& s){
        return a*s.b-b*s.a<0;
    }
    bool operator==(const node&s){
        return a==s.a and b==s.b;
    }
    node operator*(const node&s){
        node st(a*s.a,b*s.b);
        return st;
    }
    node operator-(const node&s){
        node st(a*s.b-b*s.a,b*s.b);
        return st;
    }
};
P line[int(1e5+5)];

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_prictice\\in.txt","r",stdin); 
    #endif
    
    int t;
    cin>>t;
    // scanf("%d",&t);
    while(t--)
    {
        LL x1,x2,y1,y2;
        int n;
        cin>>n;
        vector<LL> infi;
        LL size=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x1>>y1>>x2>>y2;
            if(x1==x2) infi.push_back(x1);
            else
            {
                line[size++].k=node(y2-y1,x2-x1);
                line[size].b;
            }
            
        }

    }
    return 0;
}
