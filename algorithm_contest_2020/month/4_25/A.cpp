#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);  
    #endif
    
    int t;cin>>t;
    while(t--)
    {
        int a,b,c;cin>>a>>b>>c;
        int tmp=INT_MAX;
        tmp=min(a,tmp);
        tmp=min(b,tmp);
        tmp=min(c,tmp);
        int ans=tmp*10;
        a-=tmp;
        b-=tmp;
        c-=tmp;
        tmp=INT_MAX;
        if(a==b and b==c){//相等
            cout<<ans<<endl;
            continue;
        }
        if(a==b and b==0){//某两项相等
            cout<<ans-c*2<<endl;
            continue;
        }
        if(a==c and c==0){
            cout<<ans-b*2<<endl;
            continue;
        }
        if(b==c and c==0){
            cout<<ans-a*2<<endl;
            continue;
        }
        if(a!=0) tmp=min(a,tmp);//都！相等
        if(b!=0) tmp=min(b,tmp);
        if(c!=0) tmp=min(c,tmp);
        ans+=4*tmp;
        a-=tmp;
        b-=tmp;
        c-=tmp;
        if(a>0) ans-=2*a;
        if(b>0) ans-=2*b;
        if(c>0) ans-=2*c;
        cout<<ans<<endl;
    }
    

    return 0;
}