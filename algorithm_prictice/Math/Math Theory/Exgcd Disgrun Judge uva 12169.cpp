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
// 注意LL
LL exgcd(LL a,LL b,LL &x,LL &y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    else{
        LL d=exgcd(b,a%b,y,x);
        y-=x*(a/b);
        return d;
    }
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_prictice\\in.txt","r",stdin); 
    #endif
    
    LL n;cin>>n;
    // 鬼知道为什么 WA 
    
    // vector<LL> num1(n+5),num2(n+5);//num开城LL
    // for(int i=1;i<=n;i++) cin>>num1[i];

    // // 枚举a,同时计算b
    // LL mod=10001;
    // bool flag=true;
    // for(LL a=0;a<mod;a++)
    // {
    //     LL b,k;
    //     LL d=exgcd(mod,(a+1),k,b);
    //     LL c=(num1[2]-a*a*num1[1]);
    //     if(c%d!=0) continue;//无解
    //     b*=c/d;
    //     // 验证是否正确
        
    //     for(int i=1;i<=n and flag==true;i++)
    //     {
    //         num2[i]=(a*num1[i]+b)%mod;
    //         if(i+1<=n)
    //             if(num1[i+1]!= (a*num2[i]+b)%mod )
    //                 flag=false;
    //     }
    //     if(flag==true) 
    //         break;
    // }
    // for(int i=1;i<=n;i++) cout<<num2[i]<<endl;

    // 两种做法的差距再哪里啊？？？？
    vector<LL> x(n*2+5),r(n*2+5);
    for(int i=1;i<=2*n;i+=2) cin>>x[i];
    LL mod=10001;
    for(LL a=0;a<mod;a++)
    {
        LL b,k;
        LL d=exgcd(mod,a+1,k,b);
        LL c=x[3]-a*a*x[1];
        if(c%d!=0) continue;
        b*=c/d;

        bool flag=true;
        r[1]=x[1];
        for(int i=2;i<=2*n;i++)
        {
            r[i]=(r[i-1]*a+b)%mod;
            if(i&1 and r[i]!=x[i]){
                flag=false;
                break;
            }
        }
        if(flag==true) break;
    }
    for(int i=2;i<=2*n;i+=2) cout<<r[i]<<endl;
    return 0;
}