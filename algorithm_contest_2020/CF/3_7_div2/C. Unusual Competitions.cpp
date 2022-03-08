#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
//Wrong answer on text 6
//补：ac,好像也不难，为什么当时没有想法呢？还是思路差了临门一脚
//关键一句： 从第一个异常的右括号开始，知道区间内平衡，就是一次操作
int main()
{
    int n;cin>>n;
    cin>>(s+1);
    int a=0,b=0;
    long long cnt=0;
    bool flag=false;
    int l;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='(') a++;
        if(s[i]==')') b++;
        if(b>a and flag==false) flag=true,l=i;;
        if(flag==true and a==b){
            flag=false;
            cnt+=i-l+1;
            a=b=0;
        }
        if(flag==false and a==b)
            a=b=0;
    }
    if(a==0 and b==0)
        cout<<cnt<<endl;
    else
        cout<<-1<<endl;
    return 0;
}