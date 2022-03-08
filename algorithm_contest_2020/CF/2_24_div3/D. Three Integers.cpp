#include<bits/stdc++.h>
using namespace std;
//我好垃圾！！！
//B,C 毫无意义的WA一下，到D以后，一个小时做不出来一道，唉！
//补：暴力枚举+剪枝，伪n^3，思路一：枚举a,b,c,最多4e5次; 思路二：枚举倍数一和倍数二
//官方题解： A枚举a，取值是1~2*a；如果A大于2*a，那么直接让A=1；
//          B枚举b，A~2*b，然后C由两种取值，全部尝试，O(N*lg N)
void solve1(int a,int b,int c)
{
    int ans=abs(b-a)+abs(c-b);
    int ia,ib,ic;
    for(int i=1;i<=10032;i++)//10000不正确，必须是10032至少，大神的数据。搞成2e4也能过
        for(int j=i;j<=10032;j+=i)//原因是输入<1e4,但是输出没有限定；
            for(int k=j;k<=10032;k+=j)
            {
                int detal=abs(i-a)+abs(j-b)+abs(k-c);
                if(ans>=detal)  {
                    ia=i,ib=j,ic=k;
                    ans=detal;
                }
            }
    cout<<ans<<endl<<ia<<" "<<ib<<" "<<ic<<endl;
}
int main()
{
    int T;
    //freopen("D:/code/in.txt","r",stdin);
    cin>>T;
    while(T--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        solve1(a,b,c);
    }
    return 0;
}