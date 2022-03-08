#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<long long,int>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;
bool cmp(const P& a,const P&b){
    return a.x<b.x;
}
// WA
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
        int n;cin>>n;
        vector<P > a(n+1);
        int cnta=0,cntb=0;
        int x;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            if(x<=0){
                a[i]=m_p(-x,-1);
                cnta++;
            }
            else{
                a[i]=m_p(x,1);
                cntb++;
            }
        }
        sort(a.begin()+1,a.end(),cmp);
        if(n==5){
            cout<<LL(a[1].x*a[1].y)*LL(a[5].x*a[5].y)*LL(a[2].x*a[2].y)*LL(a[3].x*a[3].y)*LL(a[4].x*a[4].y)<<endl;
            continue;
        }
        LL ans=1;
        int cnt=0;
        LL tmp1=-1,tmp2=-1;
        int tmp3=-1;//保存最近的一个正数
        if(cntb>0)
        {   //存在正数，答案一定是正数
            int i;
            for(i=n;i>=1;i--)
            {
                if(a[i].y==1){
                    ans*a[i].x;
                    tmp3=a[i].x;
                    cnt++;
                }
                else{
                    if(tmp1==-1) tmp1=a[i].x;
                    else tmp2=a[i].x;
                }
                if(cnt<4 and tmp1!=-1 and tmp2!=-1){
                    ans*=tmp1*tmp2;
                    tmp1=-1;
                    tmp2=-1;
                    cnt+=2;
                }
                if(cnt==5) break;
            }
            if(cnt!=5)//没有找够,必然是多一个-，现在cnt=4;
            {
                LL l=-1,r=-1;//l存一个负数，r存一个正数
                for(;i>=1;i--){
                    if(i<=0) l=a[i].y;
                    if(i>0) r=a[i].y;
                    if(l!=-1 and r!=-1) break;
                }
                
                if(tmp3==-1)//前四个都是负数
                {
                    // 因为存在正数，r一定会找到
                    cout<<ans*r<<endl;
                }
                else
                {
                    if(l!=-1 and r==-1)//找到一个负数，但是没有正数
                    ;
                }
                
                
            }
        }
        else{
            cout<<LL(a[1].x*a[1].y)*LL(a[5].x*a[5].y)*LL(a[2].x*a[2].y)*LL(a[3].x*a[3].y)*LL(a[4].x*a[4].y)<<endl;
        }

    }
    return 0;
}