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


int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif

    int t;
    cin>>t;
    while(t--)
    {
        vector<int> c(4),a(6);
        cin>>c[1]>>c[2]>>c[3];
        for(int i=1;i<=5;i++) cin>>a[i];
        bool flag=true;
        for(int i=1;i<=3;i++){
            c[i]-=a[i];
            a[i]=0;
            if(c[i]<0) flag=false;
        }
        if(flag==false){
            cout<<"NO"<<endl;
            continue;
        }
        int tmp=min(c[1],a[4]);
        c[1]-=tmp;
        a[4]-=tmp;
        tmp=min(c[2],a[5]);
        c[2]-=tmp;
        a[5]-=tmp;

        if(a[4]+a[5]<=c[3]) flag=true;
        else flag=false;
        if(flag==true) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
