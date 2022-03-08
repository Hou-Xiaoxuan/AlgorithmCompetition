#include<bits/stdc++.h>
using namespace std;
//补：阶乘与其他数据不同的地方在于其因数也是递增的。比如 x！由9个质因数2，（x+1）！因数2的个数一定大于9
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int p;cin>>p;
        int ans=0;
        for(int i=2;i*i<=p;i++)
        {
            if(p%i) continue;
            int cnt=0;
            while(p%i==0) {p/=i; cnt++;}
            int tmp=0;
            for(int j=i;;j+=i)
            {
                int n=j;
                while(n%i==0) {n/=i; tmp++;}//tmp为j的阶乘中i的个数
                if(tmp>=cnt){
                    ans=max(ans,j);
                    break；
                }
            }
        }
    cout<<max(ans,p)<<endl;//if(p>ans)说明最后剩下一个较大的质数没有计算，这个质数的阶乘符合全部条件
    }
    
    return 0;
}