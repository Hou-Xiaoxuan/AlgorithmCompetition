#define _USE_MATH_DEFINES
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
//ÊÖÉú°¡£¬ÆæÆæ¹Ö¹ÖµÄ´íÎó
LL getnext(LL a)
{
    LL nn=a%10,mm=a%10;
    LL ans=a;
    while(a)
    {
        nn=min(nn,a%10);
        mm=max(mm,a%10);
        a/=10;
    }
    return ans+mm*nn;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);  
    cout<<"Debug"<<endl;
    #endif
    
    int t;cin>>t;
    while(t--)
    {
        LL a,k;
        cin>>a>>k;
        LL cnt=a;
        bool flag=true;
        if(k==1){
            cout<<a<<endl;
            continue;
        }
        for(int i=1;i<k and flag==true;i++)
        {
            cnt=getnext(a);
            //cout<<i<<"-"<<cnt<<endl;
            if(cnt==a)
                flag=false;
            else 
                a=cnt;
        }
        cout<<a<<endl;
    }
    return 0;
}