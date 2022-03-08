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
// 奇妙的证明，感觉好像不是我能过的题……
// 首先转行陈前缀和问题，f[M]表示最大值不超过M时的前缀和最小值(M-f[M])为疑似答案
// 想要最大值+2的话，最小值最多增加+2，可能不会增加，情况变差，因此选择最大值最小是最优的，然而不知道为什么，还要考虑最大值增加1的情况
// 先将所有的？变成-1.找到最小值的最大值，接着返回 min(Z-f[Z],Z+1-f[Z+1])即可

const int N=1e6+50;
int sum[N+5]={0},mx[N+5]={0},n;//存前缀和与i往后的最大前缀和为多少
bool mark[N+5];
char str[N+5];
int f(int M)
{
    static int num[N+5];
    num[0]=0;//要加上这一句，?????
    for(int i=1,cnt=0;i<=n;i++)
    {
        if(mark[i]==true){
            if(mx[i]+2*(cnt+1)<=M) num[i]=1,cnt++;
            else num[i]=-1;
        }
        else num[i]= (str[i]=='0'?-1:1);
    }
    for(int i=1;i<=n;i++) num[i]+=num[i-1];
    return *min_element(num,num+n+1);//并且从0开始，意思是返回值不能大于0……啊，最小值大于0的
}
// int f(int M)
// {
//     vector<int> num(n+5);
//     for(int i=1,cnt=0;i<=n;i++)
//     {
//         if(mark[i]==true){
//             if(mx[i]+2*(cnt+1)<=M) num[i]=1,cnt++;
//             else num[i]=-1;
//         }
//         else num[i]= (str[i]=='0'?-1:1);
//     }
//     for(int i=1;i<=n;i++) num[i]+=num[i-1];
//     return *min_element(num.begin()+1,num.begin()+n+1);
// }
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    while(cin>>(str+1))
    {
        n=strlen(str+1);
        for(int i=1;i<=n;i++)
        {
            if(str[i]=='?') mark[i]=1;
            if(str[i]=='1') sum[i]=sum[i-1]+1;
            else sum[i]=sum[i-1]-1;
        }
        for(int i=n;i>=0;i--)
        {
            mx[i]=sum[i];
            // if(i!=n) mx[i]=max(mx[i],mx[i+1]);
            if(i!=n) if(mx[i]<mx[i+1]) mx[i]=mx[i+1],1;
        }
        int Z=mx[0];
        cout<<min(Z-f(Z),(Z+1)-f(Z+1))<<endl;

        memset(sum,0,sizeof(sum));
        memset(mx,0,sizeof(mx));
        memset(str,0,sizeof(str));
        memset(mark,0,sizeof(mark));
    }
    return 0;
}
